/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:37:11 by mazor             #+#    #+#             */
/*   Updated: 2020/10/20 17:37:59 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checks.h"

void	check_scene(t_scene *scene)
{
	if (!scene->is_resol_set)
		print_scene_error(10, scene);
	if (!scene->is_light_set)
		print_scene_error(11, scene);
	if (!scene->cams)
		print_scene_error(12, scene);
	if (scene->scene_error)
	{
		free_scene(scene);
		exit(-1);
	}
}

void	check_file_extension(const char *filename)
{
	while (*filename)
		filename++;
	filename -= 3;
	if (ft_strcmp(filename, ".rt"))
		print_and_exit_error(2);
}

void	validate_elem(char **elem_info, int line_num, t_scene *scene)
{
	scene->scene_error = FALSE;
	if (!(ft_strcmp(elem_info[0], "R")))
		validate_resolution(elem_info, line_num, scene);
	else if (!(ft_strcmp(elem_info[0], "A")))
		validate_ambient_light(elem_info, line_num, scene);
	else if (!(ft_strcmp(elem_info[0], "c")))
		validate_camera(elem_info, line_num, scene);
	else if (!(ft_strcmp(elem_info[0], "l")))
		validate_spot_light(elem_info, line_num, scene);
	else if (!(ft_strcmp(elem_info[0], "sp")))
		validate_sphere(elem_info, line_num, scene);
	else if (!(ft_strcmp(elem_info[0], "pl")))
		validate_plane(elem_info, line_num, scene);
	else if (!(ft_strcmp(elem_info[0], "sq")))
		validate_square(elem_info, line_num, scene);
	else if (!(ft_strcmp(elem_info[0], "cy")))
		validate_cylinder(elem_info, line_num, scene);
	else if (!(ft_strcmp(elem_info[0], "tr")))
		validate_triangle(elem_info, line_num, scene);
	else if (elem_info[0][0] == '#')
		return ;
	else
		print_validation_error(3, line_num, scene);
}
