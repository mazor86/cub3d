/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:19:25 by mazor             #+#    #+#             */
/*   Updated: 2020/10/21 23:15:49 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "errors.h"
#include "checks.h"
#include "structures.h"
#include "parse.h"
#include "mlx.h"
#include <stdio.h> //


static void	init_scene(t_scene *scene, int fd)
{
	t_mlx	mlx;

	if (!(mlx.mlx_ptr = mlx_init()))
	{
		close(fd);
		print_and_exit_error(8);
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
}

int			main(int ar, char **av)
{
	int			fd;
	t_scene		scene;

	if (ar < 2 || ar > 3 || (ar == 3 && ft_strcmp(av[2], "--save")))
		print_and_exit_error(1);
	check_file_extension(av[1]);
	if ((fd = open(av[1], O_RDONLY)) != -1)
	{
		init_scene(&scene, fd);
		parse_scene(fd, &scene);
		close(fd);
	}
	else
		print_and_exit_error(7);
	check_scene(&scene);
	ft_print_scene(&scene);//	
	return (0); //rm
}
