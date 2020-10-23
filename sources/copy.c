/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:47:48 by mazor             #+#    #+#             */
/*   Updated: 2020/10/23 17:55:34 by mazor            ###   ########.fr       */
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