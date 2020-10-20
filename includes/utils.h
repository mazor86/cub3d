/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 01:21:59 by mazor             #+#    #+#             */
/*   Updated: 2020/10/21 00:26:19 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <math.h>
# include "libft.h"
# include "structures.h"
# include "math_utils.h"

void	free_scene(t_scene *scene);
int		free_ptr_to_ptr(char **elem_info);
int		is_all_digit(char *s);
int		ft_is_float(char *s);
double	ft_atof(char *str);
int		is_rgb_color(char *str_color, t_scene *scene);
int		ft_count_char(char *str, char c);
int		is_point(char *str, t_vec *array);
int		is_normal_vector(char *str, t_vec *vector);

/*
** t_vec	str_to_vec(char *str);
*/

#endif 
