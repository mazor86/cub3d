/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:37:39 by mazor             #+#    #+#             */
/*   Updated: 2020/10/13 20:32:41 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

#define STD_ERR 2

void	print_error(int err_num)
{
	ft_putendl_fd("Error", STD_ERR);
	if (err_num == 1)
		ft_putendl_fd("usage: ./miniRT <scene_name> [--save]", STD_ERR);
	if (err_num == 2)
		ft_putendl_fd("File extension must be \".rt\"", STD_ERR);
	exit(err_num);
}