/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:52:32 by mazor             #+#    #+#             */
/*   Updated: 2020/10/28 17:28:06 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_vec	diffusion_light(t_inter inter, t_scene *scene)
{
	t_list	*light_src;
	t_light	light;
	t_vec	color[2];
	t_vec	l_ray;
	double	cosinus;

	color[0] = new_vec(0, 0, 0);
	light_src = scene->lights;
	while (light_src)
	{
		light = *(t_light*)light_src->content;
		l_ray = vec_sub(light.pos, inter.pos);
		color[1] = vec_mult_num(color_to_vec(light.color), light.intens);
		cosinus = scalar_product(l_ray, inter.norm) / l_ray.len;
		if (cosinus > 0)
			color[0] = vec_add(color[0], vec_mult_num(color[1], cosinus));
		light_src = light_src->next;
	}
	color[1] = vec_mult_num(color_to_vec(scene->amb_color), scene->amb_intens);
	color[0] = vec_add(color[0], color[1]);
	return (color[0]);
}