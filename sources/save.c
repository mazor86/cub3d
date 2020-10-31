/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:08:45 by mazor             #+#    #+#             */
/*   Updated: 2020/10/31 13:41:02 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save_bmp.h"

static void	fill_header(unsigned char *bitmap, int width, int height)
{
	int		num;

	num = 19778;
	ft_memmove(bitmap, &num, 2);
	num = 54;
	ft_memmove(bitmap + 10, &num, 4);
	num = 40;
	ft_memmove(bitmap + 14, &num, 4);
	ft_memmove(bitmap + 18, &width, 4);
	height = -height;
	ft_memmove(bitmap + 22, &height, 4);
	num = 1;
	ft_memmove(bitmap + 26, &num, 2);
}

void		save_bmp(t_scene *scene)
{
	int				fd;
	int				bmp_size;
	unsigned char	*bitmap;
	t_img			*img;
	char			*bmp_name;

	img = *(scene->images);
	bmp_size = scene->mlx.w * scene->mlx.h * img->bpp / 8 + 54;
	if (!(bitmap = ft_calloc(sizeof(char), bmp_size)))
		print_and_exit_error(14, scene);
	fill_header(bitmap, scene->mlx.w, scene->mlx.h);
	ft_memmove(bitmap + 28, &(img->bpp), 2);
	ft_memmove(bitmap + 54, img->addr, bmp_size - 54);
	bmp_name = "screenshot.bmp";
	fd = open(bmp_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	write(fd, bitmap, bmp_size);
	close(fd);
	free(bitmap);
	exit(0);
	free_scene(scene);
}