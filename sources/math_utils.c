/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 22:51:47 by mazor             #+#    #+#             */
/*   Updated: 2020/10/28 12:21:11 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_utils.h"

double		calc_vec_len(t_vec *vec)
{
	vec->len2 = vec->x * vec->x + vec->y * vec->y + vec->z * vec->z;
	vec->len = sqrt(vec->len2);
	return (vec->len);
}

t_vec		get_norm(t_vec *vector)
{
	calc_vec_len(vector);
	if (fabs(vector->len - 1) < EPSILON)
		return (*vector);
	if (vector->len < EPSILON)
		return (*vector);
	*vector = vec_mult_num(*vector, (1 / vector->len));
	return (*vector);
}
