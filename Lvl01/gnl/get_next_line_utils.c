/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalemu <zalemu@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:33:50 by zalemu            #+#    #+#             */
/*   Updated: 2025/10/13 11:33:51 by zalemu           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (s && *s)
	{
		if (*s == (unsigned char) c)
			return ((char *) s);
		s++;
	}
	if (s && *s == (unsigned char) c)
		return ((char *) s);
	return (NULL);
}

char	*ft_strjoin(char *prev_line, char *buffer)
{
	char	*line;
	size_t	i;
	size_t	j;

	if (!prev_line && !*buffer)
		return (NULL);
	line = (char *) malloc(ft_strlen(prev_line) + ft_strlen(buffer) + 1);
	if (!line)
	{
		free(prev_line);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (prev_line && prev_line[i])
	{
		line[i] = prev_line[i];
		i++;
	}
	while (buffer && buffer[j])
		line[i++] = buffer[j++];
	line[i] = '\0';
	free(prev_line);
	return (line);
}
