/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 01:21:10 by mazor             #+#    #+#             */
/*   Updated: 2020/10/28 00:42:02 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_scene(t_scene *scene)
{
	ft_lstclear(&(scene->cams), free);
	ft_lstclear(&(scene->lights), free);
	ft_lstclear(&(scene->objs), free);
	free(scene);
	scene = NULL;
	free_ptr_to_ptr(scene->images);
	scene->images = NULL;
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

int		is_all_digit(char *s)
{
	if (!ft_strlen(s))
		return (0);
	while (*s)
	{
		if (!ft_isdigit(*s++))
			return (0);
	}
	return (1);
}

int		is_rgb_color(char *str_color, t_color *color)
{
	char		**channel;
	int			i;

	if (ft_count_char(str_color, ',') != 2)
		return (0);
	channel = ft_split(str_color, ',');
	i = 0;
	while (channel[i])
	{
		if (!(is_all_digit(channel[i++])))
			return (free_ptr_to_ptr(channel));
	}
	if (i != 3)
		return (free_ptr_to_ptr(channel));
	color->t = 0;
	color->r = ft_atoi(channel[0]);
	color->g = ft_atoi(channel[1]);
	color->b = ft_atoi(channel[2]);
	free_ptr_to_ptr(channel);
	if (color->r > 255 || color->g > 255 || color->b > 255)
		return (0);
	return (1);
}

/*
** t_vec	str_to_vec(char *str)
** {
** 	t_vec	vector;
** 	char	**position;
**
** 	position = ft_split(str, ',');
** 	vector.x = ft_atof(position[0]);
** 	vector.y = ft_atof(position[1]);
** 	vector.z = ft_atof(position[2]);
** 	free_ptr_to_ptr(position);
** 	return (vector);
** }
*/

int		is_point(char *str, t_vec *vector)
{
	char	**coordinates;
	int		i;

	if (ft_count_char(str, ',') != 2)
		return (0);
	coordinates = ft_split(str, ',');
	i = 0;
	while (coordinates[i])
	{
		if (!ft_is_float(coordinates[i++]))
			return (free_ptr_to_ptr(coordinates));
	}
	if (i != 3)
		return (free_ptr_to_ptr(coordinates));
	vector->x = ft_atof(coordinates[0]);
	vector->y = ft_atof(coordinates[1]);
	vector->z = ft_atof(coordinates[2]);
	calc_vec_len(vector);
	free_ptr_to_ptr(coordinates);
	return (1);
}

int		is_normal_vector(char *str, t_vec *vector)
{
	if (!is_point(str, vector))
		return (0);
	if (fabs(vector->x) > 1 || fabs(vector->y) > 1 || fabs(vector->z) > 1)
		return (0);
	if (vector->len < EPSILON)
		return (0);
	get_norm(vector);
	return (1);
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
	new_x = vector_product(camera->norm, random);
	get_norm(&new_x);
	new_y = vector_product(camera->norm, new_x);
	get_norm(&new_y);
	camera->rot_fov_x = vec_mult_num(new_x, k);
	camera->rot_fov_y = vec_mult_num(new_y, k);
}

t_color	correct_color(t_vec vec_color)
{
	t_color		color;

	color.r = vec_color.x > 255 ? 255 : vec_color.x;
	color.g = vec_color.y > 255 ? 255 : vec_color.y;
	color.b = vec_color.z > 255 ? 255 : vec_color.z;
	color.t = 0;
	return (color);
}

t_vec	color_to_vector(t_color color)
{
	t_vec	vec_color;

	vec_color.x = (double)color.r;
	vec_color.y = (double)color.g;
	vec_color.z = (double)color.b;
	return (vec_color);
}

int		color_to_int(t_color color)
{
	return (0x00 << 24 | color.r << 16 | color.g << 8 | color.b);
}
