/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:48:13 by mazor             #+#    #+#             */
/*   Updated: 2020/10/31 15:02:33 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COPY_H
# define COPY_H

# include "structures.h"
# include "vector_operation.h"
# include "math_utils.h"

void		copy_cam(t_cam *dest, t_cam *src);
void		copy_light(t_light *dest, t_light *src);
void		copy_obj(t_obj *dest, t_obj *src);
t_vec		new_vec(double x, double y, double z);
t_color		new_color(int r, int g, int b);

#endif
