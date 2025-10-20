/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:34:42 by rspinell          #+#    #+#             */
/*   Updated: 2025/10/20 11:46:47 by rspinell         ###   ########.fr       */
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
char	*get_lines(char *str);
char	*funct_gnl(char *stash, char *buff, int fd);
char	*concat_end(char *stash, char *buff);
char	*new_stash(char *str);

int		ft_strlen(const char *s);
int		contains_n(char *str);
void	*ft_calloc(int nmemb, int size);
char	*ft_strdup(const char *s);
char	*str_realloc(char *str);

#endif
