/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 23:21:15 by mazor             #+#    #+#             */
/*   Updated: 2020/10/31 01:55:22 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

t_inter	plane_inter(t_vec *ray, t_obj obj)
{
	t_inter		inter;
	t_vec		tmp;
	double		scalar;

	inter.color = obj.color;
	inter.t = -1;
	scalar = scal_prod(obj.norm, ray[1]);
	if (fabs(scalar) < EPSILON)
		return (inter);
	tmp = vec_sub(obj.center, ray[0]);
	inter.t = scal_prod(tmp, obj.norm) / scalar;
	if (inter.t < 0)
		return (inter);
	inter.pos = vec_add(ray[0], vec_num(ray[1], inter.t));
	inter.norm = scalar < 0 ? obj.norm : vec_num(obj.norm, -1);
	return	(inter);
}