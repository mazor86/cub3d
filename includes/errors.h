/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:00:37 by mazor             #+#    #+#             */
/*   Updated: 2020/10/25 02:40:26 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <stdlib.h>
# include "libft.h"
# include "structures.h"
# include "utils.h"

# define STD_ERR 2
# define ERR_1 "Usage: ./miniRT <scene_name> [--save]"
# define ERR_2 "File extension must be \".rt\""
# define ERR_3 "no allowed type in the beginning"
# define ERR_4 "invalid number of parameters"
# define ERR_5 "invalid format of parameters"
# define ERR_6 "bad range of parameters"
# define ERR_7 "Couldn`t open scene file"
# define ERR_8 "MiniLibX initialization failed"
# define ERR_9 "Duplicating a unique scene element"
# define ERR_10 "Scene resolution is not set"
# define ERR_11 "Ambient light is not set"
# define ERR_12 "No cameras"
# define ERR_13 "Bad color"
# define ERR_14 "Some trouble with memory allocation"

void	print_and_exit_error(int err_num, t_scene *scene);
void	print_validation_error(int err_num, int l_num, t_scene *scene);
void	print_scene_error(int err_num, t_scene *scene);

#endif
