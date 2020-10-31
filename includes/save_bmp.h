/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:37:17 by mazor             #+#    #+#             */
/*   Updated: 2020/10/31 15:00:12 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAVE_BMP_H
# define SAVE_BMP_H

# include "structures.h"
# include "libft.h"
# include "errors.h"
# include <fcntl.h>
# include <unistd.h>

void	save_bmp(t_scene *scene);

#endif
