/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:48:13 by mazor             #+#    #+#             */
/*   Updated: 2020/10/23 17:52:47 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COPY_H
# define COPY_H

# include "structures.h"

void		copy_cam(t_cam *dest, t_cam *src);
void		copy_light(t_light *dest, t_light *src);

# endif