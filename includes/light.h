/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:05:03 by mazor             #+#    #+#             */
/*   Updated: 2020/10/29 13:49:57 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "structures.h"
# include "vector_operation.h"
# include "copy.h"
# include "utils.h"
# include "trace_ray.h"

t_vec	diffusion_light(t_inter inter, t_scene *scene);
t_inter	get_obj_inter(t_vec *ray, t_obj *obj, t_scene *scene);

#endif