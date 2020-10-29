/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:01:16 by mazor             #+#    #+#             */
/*   Updated: 2020/10/29 23:22:44 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"trace_ray.h"

t_inter		get_obj_inter(t_vec *ray, t_obj *obj, t_scene *scene)
{
	if (obj->type == SPHERE)
		return (sphere_inter(ray, *obj));
	else if (obj->type == PLANE)
		return (plane_inter(ray, *obj));
	else if (obj->type == SQUARE)
		return (square_inter(ray, *obj));
	else if (obj->type == TRIANGLE)
		return (triangle_inter(ray, *obj));
	else if (obj->type == CYLINDER)
		return (cylinder_inter(ray, *obj));
}

t_inter		closest_inter(t_vec *ray, t_scene *scene)
{
	t_inter		inter;
	t_inter		tmp;
	t_list		*obj;

	obj = scene->objs;
	inter.t = -1;
	while (obj)
	{
		tmp = get_obj_inter(ray, (t_obj*)(obj->content), scene);
		if (tmp.t >= 0.001 && (tmp.t < inter.t || inter.t == -1))
		{
			if (tmp.t == -1)
				tmp.color = new_color(0, 0, 0);
			inter = tmp;
		}
		obj = obj->next;
	}
	return (inter);
}