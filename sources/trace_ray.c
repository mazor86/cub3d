/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:01:16 by mazor             #+#    #+#             */
/*   Updated: 2020/10/27 23:58:25 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"trace_ray.h"

static t_inter		get_obj_inter(t_vec *ray, t_obj *obj, t_scene *scene)
{
	if (obj->type = SPHERE)
		return (sphere_inter(ray, *obj, scene));
	else if (obj->type = PLANE)
		return (plane_inter(ray, *obj, scene));
	else if (obj->type = SQUARE)
		return (square_inter(ray, *obj, scene));
	else if (obj->type = TRIANGLE)
		return (triangle_inter(ray, *obj, scene));
	else if (obj->type = CYLINDER)
		return (cylinder_inter(ray, *obj, scene));
}

t_inter		closest_inter(t_vec *ray, t_scene *scene)
{
	t_inter		inter;
	t_inter		tmp;
	t_list		*obj;

	obj = scene->objs;
	inter.t = -1;
	inter.color = new_color(255, 255, 255);
	while (obj)
	{
		tmp = get_obj_inter(ray, (t_obj*)(obj->content), scene);
		if ((tmp.t >= 0.001 && tmp.t < inter.t) || inter.t != -1)
			inter = tmp;
		obj = obj->next;
	}
	return (inter);
}