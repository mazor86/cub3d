/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 20:59:49 by mazor             #+#    #+#             */
/*   Updated: 2020/10/18 11:41:31 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "structures.h"
# include "get_next_line.h"
# include <stdlib.h>
# include "checks.h"
# include "utils.h"

void	parse_scene(int fd, t_scene *scene);

#endif
