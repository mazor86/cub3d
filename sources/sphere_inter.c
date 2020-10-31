/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_inter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:16:05 by mazor             #+#    #+#             */
/*   Updated: 2020/10/31 02:15:05 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

double	min_positive(double a, double b)
{
	if (a > 0 && b > 0)
		return (fmin(a, b));
	else
		return (fmax(a, b));
}

t_inter		sphere_inter(t_vec *ray, t_obj obj)
{
	t_inter		inter;
	t_vec		o_c;
	double		k[2];
	double		t[2];
	double		discrim;

	inter.t = -1;
	inter.color = obj.color;
	o_c = vec_sub(ray[0], obj.center);
	k[0] = 2 * scal_prod(o_c, ray[1]);
	k[1] = o_c.len2 - obj.r * obj.r;
	discrim = k[0] * k[0] - 4 * k[1];
	if (discrim < 0)
		return (inter);
	t[0] = (-k[0] - sqrt(discrim)) / 2;
	t[1] = (-k[0] + sqrt(discrim)) / 2;
	if ((discrim = min_positive(t[0], t[1])) < 0 )
		return (inter);
	inter.t = discrim;
	inter.pos = vec_add(ray[0], vec_num(ray[1], discrim));
	inter.norm = vec_sub(inter.pos, obj.center);
	get_norm(&inter.norm);
	return (inter);
}