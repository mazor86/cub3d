/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 22:52:45 by mazor             #+#    #+#             */
/*   Updated: 2020/10/28 12:25:02 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_UTILS_H
# define MATH_UTILS_H
# include <math.h>
# include "structures.h"
# include "vector_operation.h"

double		calc_vec_len(t_vec *vector);
t_vec		get_norm(t_vec *vector);

#endif
