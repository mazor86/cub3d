/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 00:08:46 by mazor             #+#    #+#             */
/*   Updated: 2020/10/28 14:49:59 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

int		exit_window(t_scene *scene)
{
	mlx_destroy_window(scene->mlx.mlx_ptr, scene->mlx.win_ptr);
	// free_scene(scene);
	exit(0);
	return (0);
}

int		key_event(int key, t_scene *scene)
{
	if (key == LEFT)
		scene->i = (scene-> i - 1 < 0) ? scene->i : scene->i - 1;
	else if (key == RIGHT)
		scene->i = scene-> i + 1 == scene->num_cams ? scene->i : scene->i + 1;
	else if (key == ESC)
		exit_window(scene);
	mlx_put_image_to_window(scene->mlx.mlx_ptr, scene->mlx.win_ptr,\
		(scene->images)[scene->i]->img, 0, 0);
	return (0);
}

void	create_window(t_scene *scene)
{
	scene->i = 0;
	scene->mlx.win_ptr = mlx_new_window(scene->mlx.mlx_ptr, scene->mlx.w,\
										scene->mlx.h, "miniRT");
	mlx_key_hook(scene->mlx.win_ptr, key_event, scene);
	mlx_hook(scene->mlx.win_ptr, 17, (1L << 17), exit_window, scene);
	mlx_put_image_to_window(scene->mlx.mlx_ptr, scene->mlx.win_ptr,\
		(scene->images)[scene->i]->img, 0, 0);
	mlx_loop(scene->mlx.mlx_ptr);
}