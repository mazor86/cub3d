/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:50:08 by mazor             #+#    #+#             */
/*   Updated: 2020/10/31 14:55:33 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_color	correct_color(t_vec vec_color)
{
	t_color		color;

	color.r = vec_color.x > 255 ? 255 : vec_color.x;
	color.g = vec_color.y > 255 ? 255 : vec_color.y;
	color.b = vec_color.z > 255 ? 255 : vec_color.z;
	color.t = 0;
	return (color);
}

t_vec	color_to_vec(t_color color)
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

int		is_trianle(t_obj tr)
{
	if (is_equal_vec(tr.a, tr.b) || is_equal_vec(tr.a, tr.c)\
								|| is_equal_vec(tr.b, tr.c))
	{
		return (0);
	}
	else
		return (1);
}

