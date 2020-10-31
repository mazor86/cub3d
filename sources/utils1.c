/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 01:21:10 by mazor             #+#    #+#             */
/*   Updated: 2020/10/31 15:11:13 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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

int		is_equal_vec(t_vec a, t_vec b)
{
	if (fabs(a.x - b.x) < EPSILON && fabs(a.y - b.y) < EPSILON\
		&& fabs(a.z - b.z) < EPSILON)
		return (1);
	else
		return (0);
}
