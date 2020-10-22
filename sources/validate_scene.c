/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 12:06:23 by mazor             #+#    #+#             */
/*   Updated: 2020/10/22 16:41:25 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validations.h"

void	validate_resolution(char **elem_info, int line_num, t_scene *scene)
{
	int		height;
	int		width;

	if (scene->is_resol_set)
		print_validation_error(9, line_num, scene);
	if (count_str_in_array(elem_info) != 3)
		print_validation_error(4, line_num, scene);
	if (!scene->line_error)
	{
		if (!is_all_digit(elem_info[1]) || !is_all_digit(elem_info[2]))
			print_validation_error(5, line_num, scene);
		else if ((width = ft_atoi(elem_info[1])) < 200)
			print_validation_error(6, line_num, scene);
		else if ((height = ft_atoi(elem_info[2])) < 200)
			print_validation_error(6, line_num, scene);
		else
		{
			scene->mlx.size_x = (int)fmin(width, scene->mlx.screen_x);
			scene->mlx.size_y = (int)fmin(height, scene->mlx.screen_y);
			scene->is_resol_set = TRUE;
		}
	}
}

void	validate_ambient_light(char **elem_info, int line_num, t_scene *scene)
{
	double		intens;
	t_color		color;

	if (scene->is_light_set)
		print_validation_error(9, line_num, scene);
	if (count_str_in_array(elem_info) != 3)
		print_validation_error(4, line_num, scene);
	if (!scene->line_error)
	{
		if (ft_is_float(elem_info[1]) <= 0)
			print_validation_error(5, line_num, scene);
		else if ((intens = ft_atof(elem_info[1])) > 1)
			print_validation_error(6, line_num, scene);
		else if (!(is_rgb_color(elem_info[2], &color)))
			print_validation_error(13, line_num, scene);
		else
		{
			scene->amb_intens = intens;
			scene->is_light_set = TRUE;
			scene->amb_color = color;
		}
	}
}

void	validate_camera(char **elem_info, int line_num, t_scene *scene)
{
	t_cam		*camera;

	if (!(camera = (t_cam*)malloc(sizeof(t_cam))))
		free_scene(scene);
	if (count_str_in_array(elem_info) != 4)
		print_validation_error(4, line_num, scene);
	if (!scene->line_error)
	{
		if (!is_point(elem_info[1], &(camera->pos)))
			print_validation_error(5, line_num, scene);
		else if (!is_normal_vector(elem_info[2], &(camera->norm)))
			print_validation_error(5, line_num, scene);
		else if (!is_all_digit(elem_info[3]) || ft_atoi(elem_info[3]) > 180)
			print_validation_error(5, line_num, scene);
		else
		{
			camera->fov = ft_atoi(elem_info[3]);
			ft_lstadd_front(&(scene->cams), ft_lstnew(camera));
		}
	}
}

void	validate_spot_light(char **elem_info, int line_num, t_scene *scene)
{
	t_light		*light;

	if (!(light = (t_light*)malloc(sizeof(t_light))))
		free_scene(scene);
	if (count_str_in_array(elem_info) != 4)
		print_validation_error(4, line_num, scene);
	if (!scene->line_error)
	{
		if (!is_point(elem_info[1], &(light->pos)))
			print_validation_error(5, line_num, scene);
		else if (ft_is_float(elem_info[2]) <= 0)
			print_validation_error(5, line_num, scene);
		else if ((light->intens = ft_atof(elem_info[2])) > 1)
			print_validation_error(6, line_num, scene);
		else if (!(is_rgb_color(elem_info[3], &(light->color))))
			print_validation_error(13, line_num, scene);
		else
		{
			light->type = SPOT;
			ft_lstadd_front(&(scene->lights), ft_lstnew(light));
		}
	}
}
