/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_inter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 23:25:19 by mazor             #+#    #+#             */
/*   Updated: 2020/10/31 04:02:49 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

static double	solve_quadro(double a, double b, double c, double *answers)
{
	double disc;

	if (a == 0 && b == 0)
		return (-1);
	if (a == 0)
	{
		answers[0] = c / b;
		return (1);
	}
	b /= a;
	c /= a;
	a = 1;
	disc = b * b - 4 * a * c;
	if (disc >= 0)
	{
		answers[0] = (-b - sqrt(disc)) / (2 * a);
		answers[1] = (-b + sqrt(disc)) / (2 * a);
	}
	return (disc);
}

static t_inter	format_inter(double t, t_vec pos, t_vec norm, t_color color)
{
	t_inter		inter;

	inter.t = t;
	inter.color = color;
	inter.pos = pos;
	inter.norm = norm;
	get_norm(&inter.norm);
	return (inter);
}

t_inter			cylinder_inter(t_vec *ray, t_obj cy)
{
	t_inter		inter;
	t_cyl_tmp	t;

	inter.t = -1;
	t.tmp_a = vec_sub(ray[1], vec_num(cy.norm, scal_prod(ray[1], cy.norm)));
	t.del_p = vec_sub(ray[0], cy.center);
	t.b = 2 * scal_prod(vec_sub(ray[1], vec_num(cy.norm, scal_prod(ray[1],\
			cy.norm))),vec_sub(t.del_p, vec_num(cy.norm,\
			scal_prod(t.del_p, cy.norm))));
	t.tmp_c = vec_sub(t.del_p, vec_num(cy.norm, scal_prod(t.del_p, cy.norm)));
	t.c = t.tmp_c.len2 - cy.r * cy.r;
	t.disc = solve_quadro(t.tmp_a.len2, t.b, t.c, t.roots);
	if (t.disc < 0)
		return (inter);
	t.disc = min_positive(t.roots[0], t.roots[1]);
	t.intersect = vec_add(ray[0], vec_num(ray[1], t.disc));
	t.vec_center2inter = vec_sub(t.intersect, cy.center);
	t.h = vec_num(cy.norm, scal_prod(t.vec_center2inter, cy.norm));
	t.n = vec_sub(t.vec_center2inter, t.h);
	if (t.h.len > cy.height)
		return (inter);
	inter = format_inter(t.disc, t.intersect, t.n, cy.color);
	if (scal_prod(inter.norm, ray[1]) > 0)
		inter.norm = vec_num(inter.norm, -1);
	return	(inter);
}

