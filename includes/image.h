/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 14:54:54 by mazor             #+#    #+#             */
/*   Updated: 2020/10/31 14:59:57 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "structures.h"
# include "math_utils.h"
# include "vector_operation.h"
# include "utils.h"
# include "trace_ray.h"
# include "mlx.h"
# include "light.h"

void	create_images(t_scene *scene);

#endif
