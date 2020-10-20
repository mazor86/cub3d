/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:37:39 by mazor             #+#    #+#             */
/*   Updated: 2020/10/19 15:36:00 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

void	print_and_exit_error(int err_num)
{
	ft_putendl_fd("Error", STD_ERR);
	if (err_num == 1)
		ft_putendl_fd(ERR_1, STD_ERR);
	else if (err_num == 2)
		ft_putendl_fd(ERR_2, STD_ERR);
	else if (err_num == 7)
		ft_putendl_fd(ERR_7, STD_ERR);
	else if (err_num == 8)
		ft_putendl_fd(ERR_8, STD_ERR);
	exit(err_num);
}

void	print_validation_error(int err_num, int line_num, t_scene *scene)
{
	if (!scene->scene_error)
		ft_putendl_fd("Error", STD_ERR);
	scene->scene_error = TRUE;
	ft_putstr_fd("Line ", STD_ERR);
	ft_putnbr_fd(line_num, STD_ERR);
	ft_putstr_fd(": ", STD_ERR);
	if (err_num == 3)
		ft_putendl_fd(ERR_3, STD_ERR);
	if (err_num == 4)
		ft_putendl_fd(ERR_4, STD_ERR);
	if (err_num == 5)
		ft_putendl_fd(ERR_5, STD_ERR);
	if (err_num == 6)
		ft_putendl_fd(ERR_6, STD_ERR);
	if (err_num == 9)
		ft_putendl_fd(ERR_9, STD_ERR);
}

void	print_scene_error(int err_num, t_scene *scene)
{
	if (!scene->scene_error)
		ft_putendl_fd("Error", STD_ERR);
	scene->scene_error = TRUE;
	if (err_num == 10)
		ft_putendl_fd(ERR_10, STD_ERR);
	if (err_num == 11)
		ft_putendl_fd(ERR_11, STD_ERR);
	if (err_num == 12)
		ft_putendl_fd(ERR_12, STD_ERR);
}
