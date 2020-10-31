/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:16:41 by mazor             #+#    #+#             */
/*   Updated: 2020/10/31 02:17:23 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "structures.h"
# include "vector_operation.h"
# include "math_utils.h"
# include <math.h>
# include "copy.h"

t_inter		sphere_inter(t_vec *ray, t_obj obj);
t_inter		plane_inter(t_vec *ray, t_obj obj);
t_inter		square_inter(t_vec *ray, t_obj obj);
t_inter		triangle_inter(t_vec *ray, t_obj obj);
t_inter		cylinder_inter(t_vec *ray, t_obj obj);
double		min_positive(double a, double b);

#endif