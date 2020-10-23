/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 12:00:20 by mazor             #+#    #+#             */
/*   Updated: 2020/10/23 17:56:19 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATIONS_H
# define VALIDATIONS_H

# include <math.h>
# include "libft.h"
# include "structures.h"
# include "utils.h"
# include "errors.h"
# include "copy.h"

void	validate_resolution(char **elem_info, int l_num, t_scene *scene);
void	validate_ambient_light(char **elem_info, int l_num, t_scene *scene);
void	validate_camera(char **elem_info, int l_num, t_scene *scene);
void	validate_spot_light(char **elem_info, int l_num, t_scene *scene);
void	validate_sphere(char **elem_info, int l_num, t_scene *scene);
void	validate_plane(char **elem_info, int l_num, t_scene *scene);
void	validate_square(char **elem_info, int l_num, t_scene *scene);
void	validate_triangle(char **elem_info, int l_num, t_scene *scene);
void	validate_cylinder(char **elem_info, int l_num, t_scene *scene);

#endif
