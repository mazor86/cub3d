/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:01:58 by mazor             #+#    #+#             */
/*   Updated: 2020/10/31 15:00:29 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_RAY_H
# define TRACE_RAY_H

# include "structures.h"
# include "intersection.h"
# include "copy.h"

t_inter		closest_inter(t_vec *ray, t_scene *scene);

#endif
