/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operation.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 23:08:42 by mazor             #+#    #+#             */
/*   Updated: 2020/10/27 19:31:27 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_OPERATION
# define VECTOR_OPERATION

# include "structures.h"

t_vec		vec_add(t_vec a, t_vec b);
double		scalar_product(t_vec a, t_vec b);
t_vec		vector_product(t_vec a, t_vec b);
t_vec		vec_mult_num(t_vec vector, double scalar);
t_vec		vec_sub(t_vec a, t_vec b);

#endif