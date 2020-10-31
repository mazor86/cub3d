/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 20:57:33 by mazor             #+#    #+#             */
/*   Updated: 2020/10/31 15:08:11 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	parse_element(char *line, int line_num, t_scene *scene)
{
	char **elem_info;

	elem_info = ft_split(line, ' ');
	validate_elem(elem_info, line_num, scene);
	free_ptr_to_ptr(elem_info);
}

void	parse_scene(int fd, t_scene *scene)
{
	char	*line;
	int		line_num;

	line_num = 1;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (*line)
			parse_element(line, line_num, scene);
		free(line);
		line = NULL;
		line_num++;
	}
	if (line_num && *line)
		parse_element(line, line_num, scene);
	free(line);
	line = NULL;
}
