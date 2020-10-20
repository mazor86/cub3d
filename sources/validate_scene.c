/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 12:06:23 by mazor             #+#    #+#             */
/*   Updated: 2020/10/20 14:26:21 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validations.h"

void	validate_resolution(char **elem_info, int line_num, t_scene *scene)
{
	int		height;
	int		width;

	width = 0;
	while (elem_info[width])
		width++;
	if (scene->is_resol_set)
		print_validation_error(9, line_num, scene);
	if (width != 3)
		print_validation_error(4, line_num, scene);
	if (!scene->scene_error)
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
	int			i;
	double		intens;

	i = 0;
	while (elem_info[i])
		i++;
	if (scene->is_light_set)
		print_validation_error(9, line_num, scene);
	if (i != 3)
		print_validation_error(4, line_num, scene);
	if (!scene->scene_error)
	{
		if (ft_is_float(elem_info[1]) <= 0)
			print_validation_error(5, line_num, scene);
		else if ((intens = ft_atof(elem_info[1])) > 1)
			print_validation_error(6, line_num, scene);
		else if (!(is_rgb_color(elem_info[2], scene)))
			print_validation_error(13, line_num, scene);
		else
		{
			scene->amb_intens = intens;
			scene->is_light_set = TRUE;
		}
	}
}

void	validate_camera(char **elem_info, int line_num, t_scene *scene)
{

}

void	validate_spot_light(char **elem_info, int line_num, t_scene *scene)
{

}
