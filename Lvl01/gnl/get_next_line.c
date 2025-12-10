/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalemu <zalemu@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:33:42 by zalemu            #+#    #+#             */
/*   Updated: 2025/10/13 11:33:44 by zalemu           ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_line_to_state(char *state, char *line)
{
	int		i;
	char	*new_line;

	new_line = ft_strchr(line, '\n');
	if (!new_line)
		return ;
	new_line++;
	i = 0;
	while (*new_line)
	{
		state[i++] = *new_line;
		*new_line++ = '\0';
	}
	state[i] = '\0';
}

char	*get_next_line(int fd)
{
	static char	state[BUFFER_SIZE + 1];
	char		*line;
	int			read_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	line = ft_strjoin(line, state);
	while (!ft_strchr(line, '\n'))
	{
		read_size = read(fd, state, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		state[read_size] = '\0';
		line = ft_strjoin(line, state);
		state[0] = '\0';
	}
	state[0] = '\0';
	ft_line_to_state(state, line);
	return (line);
}
