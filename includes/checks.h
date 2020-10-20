/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:12:23 by mazor             #+#    #+#             */
/*   Updated: 2020/10/19 19:24:55 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKS_H
# define CHECKS_H

# include "libft.h"
# include "structures.h"
# include "errors.h"
# include "validations.h"

void	check_file_extension(const char *filename);
void	validate_elem(char **elem_info, int l_num, t_scene *scene);
void	check_scene(t_scene *scene);

#endif
