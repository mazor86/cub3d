/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 22:51:47 by mazor             #+#    #+#             */
/*   Updated: 2020/10/24 11:33:48 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_utils.h"

double		calc_vec_len(t_vec *vec)
{
	vec->len2 = vec->x * vec->x + vec->y * vec->y + vec->z * vec->z;
	vec->len = sqrt(vec->len2);
	return (vec->len);
}

t_vec		multipl_by_scalar(t_vec *vector, double scalar)
{
	vector->x *= scalar;
	vector->y *= scalar;
	vector->z *= scalar;
	calc_vec_len(vector);
	return (*vector);
}

t_vec		normalize_vector(t_vec *vector)
{
	if (fabs(vector->len - 1) < EPSILON)
		return (*vector);
	multipl_by_scalar(vector, (1 / vector->len));
	return (*vector);
}
