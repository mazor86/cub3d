/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:47:48 by mazor             #+#    #+#             */
/*   Updated: 2020/10/24 00:35:33 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "copy.h"

void		copy_cam(t_cam *dest, t_cam *src)
{
	dest->pos = src->pos;
	dest->norm = src->norm;
	dest->fov = src->fov;
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
	}
	else
	{
		dest->center = src->center;
		dest->norm = src->norm;
		dest->diam = src->diam;
		dest->height = src->height;
	}
}