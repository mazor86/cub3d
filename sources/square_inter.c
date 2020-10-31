/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_inter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 23:23:02 by mazor             #+#    #+#             */
/*   Updated: 2020/10/31 01:55:22 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

static void		calc_vertex_square(t_vec *e, t_obj *obj)
{
	t_vec	sq_abs;
	t_vec	sq_ord;
	double	h;
	t_vec	c[3];

	if (obj->norm.x != 0 || obj->norm.z != 0)
		sq_abs = new_vec(0, 1, 0);
	else
		sq_abs = new_vec(1, 0, 0);
	sq_ord = vec_prod(obj->norm, sq_abs);
	get_norm(&sq_ord);
	h = obj->height / 2;
	c[0] = obj->center;
	e[0] = vec_add(c[0], vec_num(sq_ord, h));
	e[0] = vec_add(e[0], vec_num(sq_abs, h));
	c[1]= vec_add(c[0], vec_num(sq_ord, h));
	c[1] = vec_add(c[1], vec_num(sq_abs, -h));
	c[2] = vec_add(c[0], vec_num(sq_ord, -h));
	c[2] = vec_add(c[2], vec_num(sq_abs, h));
	e[1] = vec_sub(c[1], e[0]);
	e[2] = vec_sub(c[2], e[0]);
}

t_inter			square_inter(t_vec *ray, t_obj obj)
{
	t_inter		inter_pl;
	t_inter		inter;
	t_vec		e[3];
	t_vec		tmp;
	double		proj[2];

	inter.t = -1;
	inter.color = obj.color;
	inter_pl = plane_inter(ray, obj);
	if (inter_pl.t < 0)
		return (inter_pl);
	tmp = vec_sub(inter_pl.pos, obj.center);
	if (tmp.len > obj.height / sqrt(2))
		return (inter);
	calc_vertex_square(e, &obj);
	tmp = vec_sub(inter_pl.pos, e[0]);
	proj[0] = scal_prod(tmp, e[1]) / obj.height;
	proj[1] = scal_prod(tmp, e[2]) / obj.height;
	if (proj[0] <= obj.height && proj[0] >= 0 && proj[1] <= obj.height\
							&& proj[1] >= 0)
		return (inter_pl);
	return	(inter);
}
