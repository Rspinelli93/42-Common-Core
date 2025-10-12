/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:34:25 by rspinell          #+#    #+#             */
/*   Updated: 2025/10/12 18:39:01 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
* Boolean function to check if the string 
* contains a new line char ('\n'). */
int	found_n(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}
/*
* concat_end concatenates at the end of the staric string 
* (string that will be returned by get_next_line), the part
* of the buffer before finding '\n' or '\0'.
* Return: the return is null in case of coping the full buffer,
* and in case of stopping before by a '\n' it will return a pointer
* to the next char. */
char	*concat_end(static char *stat, char *buff)
{
	stat += ft_strlen(stat);
	while (*buff || *buff == '\n')
	{
		*stat = *buff;
		buff++;
		stat++;
	}
	if (*buff == '\n')
		return (buff + 1);
	return (NULL);
}