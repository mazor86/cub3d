/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:37:11 by mazor             #+#    #+#             */
/*   Updated: 2020/10/13 19:44:48 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

void	check_file_extension(const char *filename)
{
	while (*filename)
		filename++;
	filename -= 3;
	if (ft_strcmp(filename, ".rt"))
		print_error(2);
}