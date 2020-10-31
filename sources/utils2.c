/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:25:36 by mazor             #+#    #+#             */
/*   Updated: 2020/10/31 14:54:13 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_scene(t_scene *scene)
{
	int		i;

	ft_lstclear(&(scene->cams), free);
	ft_lstclear(&(scene->lights), free);
	ft_lstclear(&(scene->objs), free);
	i = 0;
	if (scene->images)
	{
		while (scene->images[i])
		{
			free(scene->images[i]);
			scene->images[i] = NULL;
			i++;
		}
		free(scene->images);
		scene->images = NULL;
	}
	free(scene);
	scene = NULL;
	exit(-1);
}

int		free_ptr_to_ptr(char **ptr_to_ptr)
{
	int		i;

	if (!ptr_to_ptr)
		return (0);
	i = 0;
	while (ptr_to_ptr[i])
	{
		free(ptr_to_ptr[i]);
		ptr_to_ptr[i++] = NULL;
	}
	free(ptr_to_ptr);
	ptr_to_ptr = NULL;
	return (0);
}

double	ft_atof(const char *str)
{
	double	integer;
	double	fraction;
	int		sign;

	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	integer = (double)ft_atoi(str) * sign;
	while (*str != '.' && *str)
		str++;
	if (!(*str))
		return (sign * integer);
	fraction = (double)ft_atoi(++str);
	while (ft_isdigit(*(str++)))
		fraction /= 10;
	return (sign * (integer + fraction));
}

int		count_str_in_array(char **array_of_str)
{
	int		i;

	i = 0;
	while (array_of_str[i])
		i++;
	return (i);
}

void	camera_rotation(t_cam	*camera)
{
	double	k;
	t_vec	random;
	t_vec	new_x;
	t_vec	new_y;

	k = tan(camera->fov / 2);
	if (camera->norm.x != 0 || camera->norm.z != 0)
		random = new_vec(0, 1, 0);
	else
		random = new_vec(1, 0, 0);
	new_x = vec_prod(camera->norm, random);
	get_norm(&new_x);
	new_y = vec_prod(camera->norm, new_x);
	get_norm(&new_y);
	camera->rot_fov_x = vec_num(new_x, k);
	camera->rot_fov_y = vec_num(new_y, k);
}
