/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 01:21:59 by mazor             #+#    #+#             */
/*   Updated: 2020/10/20 14:07:09 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include "libft.h"
# include "structures.h"

void	free_scene(t_scene *scene);
void	*free_ptr_to_ptr(char **elem_info);
int		is_all_digit(char *s);
int		ft_is_float(char *s);
double	ft_atof(char *str);
int		is_rgb_color(char *str_color, t_scene *scene);

#endif
