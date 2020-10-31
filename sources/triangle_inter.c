/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_inter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 23:24:37 by mazor             #+#    #+#             */
/*   Updated: 2020/10/31 01:55:21 by mazor            ###   ########.fr       */
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
	ptq[0] = vec_prod(ray[1], obj.e2);
	det_u_v[0] = scal_prod(obj.e1, ptq[0]);
	if (fabs(det_u_v[0]) < EPSILON)
		return (inter);
	det_u_v[0] = 1 / det_u_v[0];
	ptq[1] = vec_sub(ray[0], obj.a);
	det_u_v[1] = scal_prod(ptq[0], ptq[1]) * det_u_v[0];
	if (det_u_v[1] < 0 || det_u_v[1] > 1)
		return (inter);
	ptq[2] = vec_prod(ptq[1], obj.e1);
	det_u_v[2] = scal_prod(ray[1], ptq[2]) * det_u_v[0];
	if (det_u_v[2] < 0 || det_u_v[1] + det_u_v[2] > 1)
		return (inter);
	inter.t = scal_prod(obj.e2, ptq[2]) * det_u_v[0];
	inter.pos = vec_add(ray[0], vec_num(ray[1], inter.t));
	det_u_v[0] = scal_prod(obj.norm, ray[1]);
	inter.norm = det_u_v[0] < 0 ? obj.norm : vec_num(obj.norm, -1);
	return	(inter);
}
