/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 22:52:45 by mazor             #+#    #+#             */
/*   Updated: 2020/10/23 23:18:51 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_UTILS_H
# define MATH_UTILS_H
# include <math.h>
# include "structures.h"

double		calc_vec_len(t_vec *vector);
t_vec		normalize_vector(t_vec *vector);
t_vec		multipl_by_scalar(t_vec *vector, double scalar);

#endif
