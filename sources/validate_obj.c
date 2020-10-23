/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 12:13:05 by mazor             #+#    #+#             */
/*   Updated: 2020/10/24 01:48:18 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validations.h"

void	validate_sphere(char **elem_info, int line_num, t_scene *scene)
{
	t_obj	sphere;
	t_obj	*new_sphere;

	if (count_str_in_array(elem_info) != 4)
		print_validation_error(4, line_num, scene);
	if (!scene->line_error)
	{
		if (!is_point(elem_info[1], &(sphere.center)))
			print_validation_error(5, line_num, scene);
		else if (ft_is_float(elem_info[2]) <= 0)
			print_validation_error(5, line_num, scene);
		else if (!is_rgb_color(elem_info[3], &(sphere.color)))
			print_validation_error(13, line_num, scene);
		else
		{
			if (!(new_sphere = (t_obj*)malloc(sizeof(t_obj))))
				print_and_exit_error(14, scene);
			sphere.type = SPHERE;
			sphere.diam = ft_atof(elem_info[2]);
			copy_obj(new_sphere, &sphere);
			ft_lstadd_front(&(scene->objs), ft_lstnew(new_sphere));
		}
	}
}

void	validate_plane(char **elem_info, int line_num, t_scene *scene)
{
	t_obj	plane;
	t_obj	*new_plane;

	if (count_str_in_array(elem_info) != 4)
		print_validation_error(4, line_num, scene);
	if (!scene->line_error)
	{
		if (!is_point(elem_info[1], &(plane.center)))
			print_validation_error(5, line_num, scene);
		else if (!is_normal_vector(elem_info[2], &(plane.norm)))
			print_validation_error(5, line_num, scene);
		else if (!(is_rgb_color(elem_info[3], &(plane.color))))
			print_validation_error(13, line_num, scene);
		else
		{
			if (!(new_plane = (t_obj*)malloc(sizeof(t_obj))))
				print_and_exit_error(14, scene);
			plane.type = PLANE;
			copy_obj(new_plane, &plane);
			ft_lstadd_front(&(scene->objs), ft_lstnew(new_plane));
		}
	}
}

void	validate_square(char **elem_info, int line_num, t_scene *scene)
{
	t_obj	square;
	t_obj	*new_square;

	if (count_str_in_array(elem_info) != 5)
		print_validation_error(4, line_num, scene);
	if (!scene->line_error)
	{
		if (!is_point(elem_info[1], &(square.center)))
			print_validation_error(5, line_num, scene);
		else if (!is_normal_vector(elem_info[2], &(square.norm)))
			print_validation_error(5, line_num, scene);
		else if (!(is_rgb_color(elem_info[4], &(square.color))))
			print_validation_error(13, line_num, scene);
		else if (ft_is_float(elem_info[3]) <= 0)
			print_validation_error(5, line_num, scene);
		else
		{
			if (!(new_square = (t_obj*)malloc(sizeof(t_obj))))
				print_and_exit_error(14, scene);
			square.type = SQUARE;
			square.height = ft_atof(elem_info[3]);
			copy_obj(new_square, &square);
			ft_lstadd_front(&(scene->objs), ft_lstnew(new_square));
		}
	}
}

void	validate_triangle(char **elem_info, int line_num, t_scene *scene)
{
	t_obj	triangle;
	t_obj	*new_trianle;

	if (count_str_in_array(elem_info) != 5)
		print_validation_error(4, line_num, scene);
	if (!scene->line_error)
	{
		if (!is_point(elem_info[1], &(triangle.a)))
			print_validation_error(5, line_num, scene);
		else if (!is_point(elem_info[2], &(triangle.b)))
			print_validation_error(5, line_num, scene);
		else if (!is_point(elem_info[3], &(triangle.c)))
			print_validation_error(5, line_num, scene);
		else if (!(is_rgb_color(elem_info[4], &(triangle.color))))
			print_validation_error(13, line_num, scene);
		else
		{
			if (!(new_trianle = (t_obj*)malloc(sizeof(t_obj))))
				print_and_exit_error(14, scene);
			triangle.type = TRIANGLE;
			copy_obj(new_trianle, &triangle);
			ft_lstadd_front(&(scene->objs), ft_lstnew(new_trianle));
		}
	}
}

void	validate_cylinder(char **info, int line_num, t_scene *scene)
{
	t_obj	cylinder;
	t_obj	*new_cylinder;

	if (count_str_in_array(info) != 6)
		print_validation_error(4, line_num, scene);
	if (!scene->line_error)
	{
		if (!is_point(info[1], &(cylinder.center)))
			print_validation_error(5, line_num, scene);
		else if (!is_normal_vector(info[2], &(cylinder.norm)))
			print_validation_error(5, line_num, scene);
		else if (ft_is_float(info[3]) <= 0 || ft_is_float(info[4]) <= 0)
			print_validation_error(5, line_num, scene);
		else if (!(is_rgb_color(info[5], &(cylinder.color))))
			print_validation_error(13, line_num, scene);
		else
		{
			new_cylinder = (t_obj*)malloc(sizeof(t_obj));
			cylinder.type = CYLINDER;
			cylinder.diam = ft_atof(info[3]);
			cylinder.height = ft_atof(info[4]);
			copy_obj(new_cylinder, &cylinder);
			ft_lstadd_front(&(scene->objs), ft_lstnew(new_cylinder));
		}
	}
}
