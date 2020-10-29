/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:16:41 by mazor             #+#    #+#             */
/*   Updated: 2020/10/29 02:00:26 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "structures.h"
# include "vector_operation.h"
# include "math_utils.h"
# include <math.h>

t_inter		sphere_inter(t_vec *ray, t_obj obj, t_scene *scene);
t_inter		plane_inter(t_vec *ray, t_obj obj, t_scene *scene);
t_inter		square_inter(t_vec *ray, t_obj obj, t_scene *scene);
t_inter		triangle_inter(t_vec *ray, t_obj obj, t_scene *scene);
t_inter		cylinder_inter(t_vec *ray, t_obj obj, t_scene *scene);

#endif