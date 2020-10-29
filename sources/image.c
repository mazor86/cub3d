/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 14:54:10 by mazor             #+#    #+#             */
/*   Updated: 2020/10/29 21:00:27 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

t_color			get_ray_color(t_vec *ray, t_scene *scene)
{
	t_vec	color;
	t_inter	inter;

	inter = closest_inter(ray, scene);
	if (inter.t < 0)
		return (new_color(0, 0, 0));
	color = diffusion_light(inter, scene);
	color.x *= inter.color.r;
	color.y *= inter.color.g;
	color.z *= inter.color.b;
	return (correct_color(color));
}

static t_vec		get_ray_dir(int x, int y, t_scene *scene, t_cam *cam)
{
	t_vec	ray;
	t_vec	x_offset;
	t_vec	y_offset;
	double	width;
	double	height;

	width = (double)scene->mlx.w;
	height = (double)scene->mlx.h;
	x_offset = vec_mult_num(cam->rot_fov_x, 1 - 2. * (double)x / width);
	y_offset = vec_mult_num(cam->rot_fov_y, height / width);
	y_offset = vec_mult_num(y_offset, 1 - 2 * (double)y / height);
	ray = vec_add(x_offset, y_offset);
	ray = vec_add(ray, cam->norm);
	get_norm(&ray);
	return (ray);
}

static void		my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

static void		raytracing(t_scene *scene, t_img *img, t_cam *camera)
{
	int			x;
	int			y;
	t_vec		ray[2];
	t_color		color;

	y = 0;
	while (y < scene->mlx.h)
	{
		x = 0;
		while (x < scene->mlx.w)
		{
			ray[1] = get_ray_dir(x, y, scene, camera);
			ray[0] = camera->pos;
			color = get_ray_color(ray, scene);
			my_mlx_pixel_put(img, x, scene->mlx.h - y, color_to_int(color));
			x++;
		}
		y++;
	}
}

static void		render_image(int num, t_scene *scene, t_cam *camera)
{
	t_img	*img_ptr;
	t_img	img;
	
	img.img = mlx_new_image(scene->mlx.mlx_ptr, scene->mlx.w,\
								scene->mlx.h);
	if (!img.img)
		free_scene(scene);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.size_line, &img.end);
	if (!img.addr)
		free_scene(scene);
	raytracing(scene, &img, camera);
	img_ptr = (t_img*)malloc(sizeof(t_img));
	*img_ptr = img;
	(scene->images)[num] = img_ptr;
}

void			create_images(t_scene *scene)
{
	t_list		*camera;
	int			i;

	i = scene->num_cams;
	camera = scene->cams;
	if (!(scene->images = malloc(sizeof(t_img*) * (1 + scene->num_cams))))
		free_scene(scene);
	(scene->images)[scene->num_cams] = NULL;
	while (i)
	{
		render_image(i - 1, scene, (t_cam*)camera->content);
		camera = camera->next;
		i--;
	}
}