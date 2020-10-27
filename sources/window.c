/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 00:08:46 by mazor             #+#    #+#             */
/*   Updated: 2020/10/28 00:24:39 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	create_window(t_scene *scene)
{
	scene->mlx.win_ptr = mlx_new_window(scene->mlx.mlx_ptr, scene->mlx.w,\
										scene->mlx.h, "miniRT");
	mlx_put_image_to_window(scene->mlx.mlx_ptr, scene->mlx.win_ptr,\
		(scene->images)[0], 0, 0);
	mlx_loop(scene->mlx.mlx_ptr);
}