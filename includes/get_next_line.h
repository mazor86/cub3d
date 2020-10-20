/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 21:37:08 by mazor             #+#    #+#             */
/*   Updated: 2020/10/17 14:14:18 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

int			get_next_line(int fd, char **line);
size_t		ft_strlen_gnl(const char *s);
char		*ft_strdup_gnl(char *s);
size_t		ft_strlcpy_gnl(char *dst, const char *src, size_t size);
char		*strjoinfree(char *s1, char *s2, size_t bytes);

#endif
