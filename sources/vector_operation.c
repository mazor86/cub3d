/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 23:09:18 by mazor             #+#    #+#             */
/*   Updated: 2020/10/31 15:12:30 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_operation.h"

t_vec	vec_add(t_vec a, t_vec b)
{
	t_vec	add;

	add.x = a.x + b.x;
	add.y = a.y + b.y;
	add.z = a.z + b.z;
	calc_vec_len(&add);
	return (add);
}

t_vec	vec_sub(t_vec a, t_vec b)
{
	t_vec	sub;

	sub.x = a.x - b.x;
	sub.y = a.y - b.y;
	sub.z = a.z - b.z;
	calc_vec_len(&sub);
	return (sub);
}

double	scal_prod(t_vec a, t_vec b)
{
	double scalar;

	scalar = a.x * b.x + a.y * b.y + a.z * b.z;
	return (scalar);
}

t_vec	vec_prod(t_vec a, t_vec b)
{
	t_vec vector;

	vector.x = a.y * b.z - a.z * b.y;
	vector.y = a.z * b.x - a.x * b.z;
	vector.z = a.x * b.y - a.y * b.x;
	calc_vec_len(&vector);
	return (vector);
}

t_vec	vec_num(t_vec vector, double scalar)
{
	vector.x *= scalar;
	vector.y *= scalar;
	vector.z *= scalar;
	calc_vec_len(&vector);
	return (vector);
}
