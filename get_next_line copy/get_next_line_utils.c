/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:34:25 by rspinell          #+#    #+#             */
/*   Updated: 2025/10/20 11:10:21 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Returns the length of a string */
int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (len);
	while (s[len])
		len++;
	return (len);
}

/*
	* BOOL. Function to check if the string
	* contains a new line char ('\n'). */
int	contains_n(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*
	* Allocates memory, filling bytes with 0s */
void	*ft_calloc(int nmemb, int size)
{
	unsigned char	*ptr;
	int				i;

	i = 0;
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (i < nmemb * size)
		ptr[i++] = '\0';
	return (ptr);
}

/*
	* strdup() returns a pointer to a new duplicate of s string
	* Memory for the new string is obtained
	* with malloc(3), and can be freed with free(3). */
char	*ft_strdup(const char *s)
{
	int		len;
	char	*dest;
	char	*src;

	len = ft_strlen(s);
	src = (char *)s;
	dest = (char *) malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return ((void *) NULL);
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (dest - len);
}

/*
	* str_realloc() allocates in memory a new string, coping each byte of str
	* into the new string + BUFFER_SIZE '\0' bytes.
	* RETURN: frees the old string and returns the new one. */
char	*str_realloc(char *str)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_calloc(sizeof(char), (ft_strlen(str) + BUFFER_SIZE + 1));
	if (new == NULL)
	{
		free(str);
		return (NULL);
	}
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	if (str)
		free(str);
	return (new);
}
