/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_inter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 23:24:37 by mazor             #+#    #+#             */
/*   Updated: 2020/10/30 00:42:51 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

/*
** Moller-Trumbore algorithm
*/

t_inter	triangle_inter(t_vec *ray, t_obj obj)
{
	t_inter		inter;
	t_vec		ptq[3];
	double		det_u_v[3];

	inter.color = obj.color;
	inter.t = -1;
	ptq[0] = vector_product(ray[1], obj.e2);
	det_u_v[0] = scalar_product(obj.e1, ptq[0]);
	if (fabs(det_u_v[0]) < EPSILON)
		return (inter);
	det_u_v[0] = 1 / det_u_v[0];
	ptq[1] = vec_sub(ray[0], obj.a);
	det_u_v[1] = scalar_product(ptq[0], ptq[1]) * det_u_v[0];
	if (det_u_v[1] < 0 || det_u_v[1] > 1)
		return (inter);
	ptq[2] = vector_product(ptq[1], obj.e1);
	det_u_v[2] = scalar_product(ray[1], ptq[2]) * det_u_v[0];
	if (det_u_v[2] < 0 || det_u_v[1] + det_u_v[2] > 1)
		return (inter);
	inter.t = scalar_product(obj.e2, ptq[2]) * det_u_v[0];
	inter.pos = vec_add(ray[0], vec_mult_num(ray[1], inter.t));
	det_u_v[0] = scalar_product(inter.norm, ray[1]);
	inter.norm = det_u_v[0] < 0 ? inter.norm : vec_mult_num(inter.norm, -1);
	return	(inter);
}
