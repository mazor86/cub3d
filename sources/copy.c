/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:47:48 by mazor             #+#    #+#             */
/*   Updated: 2020/10/30 00:37:05 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "copy.h"

void		copy_cam(t_cam *dest, t_cam *src)
{
	dest->pos = src->pos;
	dest->norm = src->norm;
	dest->fov = src->fov;
	dest->rot_fov_x = src->rot_fov_x;
	dest->rot_fov_y = src->rot_fov_y;
}

void		copy_light(t_light *dest, t_light *src)
{
	dest->pos = src->pos;
	dest->intens = src->intens;
	dest->color = src->color;
	dest->type = src->type;
}

void		copy_obj(t_obj *dest, t_obj *src)
{
	dest->type = src->type;
	dest->color = src->color;
	if (dest->type == TRIANGLE)
	{
		dest->a = src->a;
		dest->b = src->b;
		dest->c = src->c;
		dest->e1 = vec_sub(dest->b, dest->a);
		dest->e2 = vec_sub(dest->c, dest->a);
		dest->norm = vector_product(dest->e2, dest->e1);
		get_norm(&(dest->norm));
	}
	else
	{
		dest->center = src->center;
		dest->norm = src->norm;
		dest->diam = src->diam;
		dest->height = src->height;
	}
	dest->r = dest->diam / 2;
}

t_vec		new_vec(double x, double y, double z)
{
	t_vec	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_color		new_color(int r, int g, int b)
{
	t_color		new;

	new.t = 0;
	new.r = r;
	new.g = g;
	new.b = b;
	return (new);
}
