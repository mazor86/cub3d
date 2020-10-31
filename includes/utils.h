/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 01:21:59 by mazor             #+#    #+#             */
/*   Updated: 2020/10/31 14:59:40 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <math.h>
# include "libft.h"
# include "structures.h"
# include "math_utils.h"
# include "copy.h"
# include "vector_operation.h"

void	free_scene(t_scene *scene);
int		free_ptr_to_ptr(char **elem_info);
int		is_all_digit(char *s);
int		is_rgb_color(char *str_color, t_color *color);
int		is_point(char *str, t_vec *array);
int		is_normal_vector(char *str, t_vec *vector);
double	ft_atof(const char *str);
int		count_str_in_array(char **array_of_str);
void	camera_rotation(t_cam *camera);
t_color	correct_color(t_vec vec_color);
t_vec	color_to_vec(t_color color);
int		color_to_int(t_color color);
int		is_equal_vec(t_vec a, t_vec b);
int		is_trianle(t_obj trianle);

#endif
