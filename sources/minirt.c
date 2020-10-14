/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:19:25 by mazor             #+#    #+#             */
/*   Updated: 2020/10/13 21:14:16 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

int			main(int ar, char **av)
{
	if (ar < 2 || ar > 3 || (ar == 3 && ft_strcmp(av[2], "--save")))
		print_error(1);
	check_file_extension(av[1]);
	
	return (0); //rm
}