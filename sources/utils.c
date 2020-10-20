/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 01:21:10 by mazor             #+#    #+#             */
/*   Updated: 2020/10/20 14:17:03 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_scene(t_scene *scene)
{
	//TODO
}

void	*free_ptr_to_ptr(char **ptr_to_ptr)
{
	int	i;

	i = 0;
	while (ptr_to_ptr[i])
	{
		free(ptr_to_ptr[i]);
		ptr_to_ptr[i++] = NULL;
	}
	free(ptr_to_ptr);
	ptr_to_ptr = NULL;
	return (NULL);
}

int		is_all_digit(char *s)
{
	if (!ft_strlen(s))
		return (0);
	while (*s)
	{
		if (!ft_isdigit(*s++))
			return (0);
	}
	return (1);
}

/*
** ft_is_float returns 0 if char *s isn`t float,
** -1, if float < 0 and
**  1, if float >= 0
*/

int		ft_is_float(char *s)
{
	int	sign;

	sign = (*s == '-') ? -1 : 1;
	if (*s == '-')
		s++;
	if (!ft_strlen(s) || !ft_strcmp(s, "."))
		return (0);
	while (*s)
	{
		if (!ft_isdigit(*s))
		{
			if (*s++ == '.')
				break ;
			return (0);
		}
		s++;
	}
	while (*s)
	{
		if (!ft_isdigit(*s++))
			return (0);
	}
	return (sign);
}

int		count_commas(char *str)
{
	int		commas;

	commas = 0;
	while (*str)
	{
		if (*str == ',')
			commas++;
		str++;
	}
	return (commas);
}

int		is_rgb_color(char *str_color, t_scene *scene)
{
	char		**channel;
	int			i;
	t_color		color;

	if (count_commas(str_color) != 2)
		return (NULL);
	channel = ft_split(str_color, ',');
	i = 0;
	while (channel[i])
	{
		if (!(is_all_digit(channel[i++])))
			return (free_ptr_to_ptr(channel));
	}
	if (i != 3)
		return (free_ptr_to_ptr(channel));
	color.t = 0;
	color.r = ft_atoi(channel[0]);
	color.g = ft_atoi(channel[1]);
	color.b = ft_atoi(channel[2]);
	free_ptr_to_ptr(channel);
	if (color.r > 255 || color.g > 255 || color.b > 255)
		return (NULL);
	scene->amb_color = color;
	return (1);
}

double	ft_atof(char *str)
{
	double	integer;
	double	fraction;
	int		sign;

	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	integer = (double)ft_atoi(str) * sign;
	while (*str != '.')
		str++;
	fraction = (double)ft_atoi(++str);
	while (ft_isdigit(*str++))
		fraction /= 10;
	return (sign * (integer + fraction));
}
