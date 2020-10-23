/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazor <mazor@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 03:41:22 by mazor             #+#    #+#             */
/*   Updated: 2020/10/23 21:39:29 by mazor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size)
{
	size_t dst_len;
	size_t src_len;

	if (!src || !dst)
		return (0);
	dst_len = (size - 1);
	src_len = ft_strlen_gnl(src);
	if (size)
	{
		while (*src && dst_len)
		{
			*dst++ = *src++;
		}
		*dst = '\0';
		dst_len--;
	}
	return ((src_len));
}

char	*ft_strdup_gnl(char *s)
{
	char	*dup;

	dup = (char*)malloc(sizeof(char) * (ft_strlen_gnl(s) + 1));
	if (!dup)
		return (NULL);
	ft_strlcpy_gnl(dup, s, ft_strlen_gnl(s) + 1);
	return (dup);
}

char	*strjoinfree(char *s1, char *s2, size_t len2)
{
	char	*joined;
	size_t	len1;

	if (!s1)
		return (NULL);
	if (!len2)
		return (s1);
	len1 = ft_strlen_gnl(s1);
	if (!(joined = (char*)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	ft_strlcpy_gnl(joined, s1, len1 + 1);
	ft_strlcpy_gnl(joined + len1, s2, len2 + 1);
	free(s1);
	s1 = NULL;
	free(s2);
	s2 = NULL;
	return (joined);
}
