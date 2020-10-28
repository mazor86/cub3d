/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:05:03 by mazor             #+#    #+#             */
/*   Updated: 2020/10/28 17:11:09 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "structures.h"
# include "vector_operation.h"
# include "copy.h"
# include "utils.h"

t_vec	diffusion_light(t_inter inter, t_scene *scene);

#endif