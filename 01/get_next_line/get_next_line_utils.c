/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:34:25 by rspinell          #+#    #+#             */
/*   Updated: 2025/10/16 19:47:20 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* 
	*Returns the length of a string */
int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (len);
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

/*
	* The strchr() function returns a pointer to the first occurrence of
	* the character c in the string s.
	* Also counts '\0' byte  to compare */
char	*ft_strchr(char *s, int c)
{
	char	*ptr;

	ptr = (char *) s;
	while (*ptr)
	{
		if (*ptr == (unsigned char) c)
			return (ptr);
		ptr++;
	}
	if (*ptr == '\0' && (unsigned char) c == '\0')
		return (ptr);
	return (NULL);
}
/*
	* The strdup() function returns a pointer to a new string which is a
    * duplicate of the string s.
	* This version copies until the end of the string or until finding
	* a new line char, whichever happens first
	! Memory for the new string is obtained
    ! with malloc(3), and can be freed with free(3). */
char	*new_strdup(char *s)
{
	int		len;
	char	*dest;
	char	*src;

	len = ft_strlen(s);
	src = (char *)s;
	dest = (char *) malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return ((void *) NULL);
	while (*src || *src == '\n')
	{
		*dest = *src;
		src++;
		dest++;
	}
	if (*src == '\n')
	{
		*dest = *src;
		dest++;
	}
	*dest = '\0';
	return (dest - len);
}
/*
	* Concatenates two specified strings and returns the resulting string.
	$ s1 is free at the end
	! Memory for the new string is obtained
    ! with malloc(3), and can be freed with free(3). */
char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	char	*dst;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = (char *) malloc(sizeof(char) * len);
	if (!dst)
		return (free(s1), NULL);
	ptr = (char *) s1;
	while (*ptr)
	{
		*dst = *ptr;
		dst++;
		ptr++;
	}
	ptr = (char *) s2;
	while (*ptr)
	{
		*dst = *ptr;
		dst++;
		ptr++;
	}
	*dst = '\0';
	free(s1);
	return ((dst - (len - 1)));
}
/*
	* ft_substr returns a substring of the string s passed as parameter.

	* str: the string to take a substring from
	* start: starting position (index) of the extracted string
	* length: length of string to return
	! Memory for the new string is obtained
    ! with malloc(3), and can be freed with free(3). */
char	*ft_substr(char *s, int start, int len)
{
	char	*ptr;
	char	*dst;
	int	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (new_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	ptr = (char *) s + start;
	i = 0;
	while (i < len)
	{
		*dst = *ptr;
		dst++;
		ptr++;
		i++;
	}
	*dst = '\0';
	return (dst - len);
}