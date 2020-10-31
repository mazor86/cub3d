/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:19:25 by mazor             #+#    #+#             */
/*   Updated: 2020/10/31 11:08:37 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_scene(t_scene *scene, int fd)
{
	t_mlx	mlx;

	if (!(mlx.mlx_ptr = mlx_init()))
	{
		close(fd);
		print_and_exit_error(8, scene);
	}
	mlx_get_screen_size(mlx.mlx_ptr, &(mlx.screen_x), &(mlx.screen_y));
	scene->mlx = mlx;
	scene->line_error = FALSE;
	scene->scene_error = FALSE;
	scene->is_resol_set = FALSE;
	scene->is_light_set = FALSE;
	scene->cams = NULL;
	scene->objs = NULL;
	scene->lights = NULL;
	scene->images = NULL;
}

int			main(int ar, char **av)
{
	int			fd;
	t_scene		*scene;

	if (!(scene = (t_scene*)malloc(sizeof(t_scene))))
		print_and_exit_error(13, scene);
	if (ar < 2 || ar > 3 || (ar == 3 && ft_strcmp(av[2], "--save")))
		print_and_exit_error(1, scene);
	check_file_extension(av[1], scene);
	fd = open(av[1], O_RDONLY);
	if (fd != -1)
	{
		init_scene(scene, fd);
		parse_scene(fd, scene);
		close(fd);
	}
	else
		print_and_exit_error(7, scene);
	check_scene(scene);
	create_images(scene);
	if (ar == 2)
		create_window(scene);
	else
		save_bmp();
}
