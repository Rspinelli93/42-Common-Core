/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:34:42 by rspinell          #+#    #+#             */
/*   Updated: 2025/10/13 13:46:55 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 16
# endif

# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*get_line(char *str);
char	*str_realloc(char *str, int b_size, int ix);
char	*concat_end(char *stash, char *buff);
int		ft_strlen(const char *s);
int		contains_n(char *str);
void	*ft_calloc(int nmemb, int size);
void	ft_bzero(void *s, int n);

#endif
