/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operation.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 23:08:42 by mazor             #+#    #+#             */
/*   Updated: 2020/10/31 02:17:53 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_OPERATION
# define VECTOR_OPERATION

# include "structures.h"
# include "math_utils.h"

t_vec		vec_add(t_vec a, t_vec b);
double		scal_prod(t_vec a, t_vec b);
t_vec		vec_prod(t_vec a, t_vec b);
t_vec		vec_num(t_vec vector, double scalar);
t_vec		vec_sub(t_vec a, t_vec b);

#endif