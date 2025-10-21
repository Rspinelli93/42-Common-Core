/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:34:42 by rspinell          #+#    #+#             */
/*   Updated: 2025/10/20 14:46:57 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*get_lines(char *str, char c);
char	*concat_end(char *stash, char *buff);
char	*new_stash(char *str);
char	*_gnl(char **stash, int fd, int ret);

int		ft_strlen(const char *s);
int		contains_n(char *str);
void	*ft_calloc(int nmemb, int size);
void	free_stash(char **stash);
char	*str_realloc(char *str);

#endif
