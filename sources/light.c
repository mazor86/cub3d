/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:52:32 by mazor             #+#    #+#             */
/*   Updated: 2020/10/29 20:57:18 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

static int	is_shadowed(t_vec *l_ray, t_scene *scene)
{
	t_inter	inter;
	t_vec	tmp;
	t_list	*obj;
	double	t_max;

	obj = scene->objs;
	t_max = l_ray[1].len;
	get_norm(&l_ray[1]);
	tmp = l_ray[1];
	tmp = vec_mult_num(tmp, 0.001);
	l_ray[0] = vec_add(tmp, l_ray[0]);
	while (obj)
	{
		inter = get_obj_inter(l_ray, (t_obj*)(obj->content), scene);
		if (inter.t > 0 && inter.t < t_max)
			return (1);
		obj = obj->next;
	}
	return (0);
}

t_vec	diffusion_light(t_inter inter, t_scene *scene)
{
	t_list	*light_src;
	t_light	light;
	t_vec	color[2];
	t_vec	l_ray[2];
	double	cosinus;

	color[0] = new_vec(0, 0, 0);
	light_src = scene->lights;
	while (light_src)
	{
		light = *(t_light*)light_src->content;
		l_ray[0] = inter.pos;
		l_ray[1] = vec_sub(light.pos, inter.pos);
		color[1] = vec_mult_num(color_to_vec(light.color), light.intens);
		cosinus = scalar_product(l_ray[1], inter.norm) / l_ray[1].len;
		if (cosinus > 0 && !is_shadowed(l_ray, scene))
			color[0] = vec_add(color[0], vec_mult_num(color[1], cosinus));
		light_src = light_src->next;
	}
	color[1] = vec_mult_num(color_to_vec(scene->amb_color), scene->amb_intens);
	color[0] = vec_add(color[0], color[1]);
	color[0] = vec_mult_num(color[0], 1. / 255);
	return (color[0]);
}