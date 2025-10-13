/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:34:25 by rspinell          #+#    #+#             */
/*   Updated: 2025/10/13 21:31:46 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Returns the length of a string */
int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

/*
	* BOOL. Function to check if the string
	* contains a new line char ('\n'). */
int	contains_n(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

/* 
	* Allocates memory, filling bytes with 0s */
void	*ft_calloc(int nmemb, int size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/* 
	* Fills bytes with 0s */
void	ft_bzero(void *s, int n)
{
	char	*str;

	str = (char *)s;
	while (n > 0)
	{
		*str = '\0';
		n--;
		str++;
	}
}
