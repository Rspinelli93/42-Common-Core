/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 23:32:15 by rick              #+#    #+#             */
/*   Updated: 2025/10/02 20:03:19 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*skipc(char *str, char c);
static int	cntwords(char *s, char c);
static char	*stralloc(int len, char *str);
static int	strclen(char *str, char c);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		words;
	char	*str;
	int		i;

	str = (char *)s;
	words = cntwords(str, c);
	i = 0;
	arr = (char **) malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	str = skipc(str, c);
	while (i < words)
	{
		arr[i] = stralloc(strclen(str, c), str);
		str += ft_strlen(arr[i]);
		str = skipc(str, c);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

/* 
SKIP C - Advances the string until it finds != 'c' or the end.

Return - ptr to that position
Params - 's' being the string to advance and 'c' the char to skip
*/
static char	*skipc(char *str, char c)
{
	if (*str != c)
		return (str);
	while (*str == c)
		str++;
	return (str);
}

/*
COUNT WORDS

Params - 's' being the string to iterate and 'c' the separator
Return - Number of strings found separated by 'c'

24. Advance in case of separator till first word
28. Control in case of all ('s' char) == 'c' or string being empty
32. Iterate over the string
34. Increment words in case of:
		- '*s' == 'c' followed by a char different than 'c'
			(Avoid 2 'c' or more in a row)
		- reaching the end of the string
40. Return the word
*/

static int	cntwords(char *s, char c)
{
	int	words;

	s = skipc(s, c);
	if (ft_strlen(s) == 0 || !s || c == '\0')
		return (0);
	words = 0;
	while (*s)
	{
		if (*s == c)
		{
			words++;
			s = skipc(s, c);
			continue ;
		}
		s++;
	}
	if (*(s - 1) != c)
		words++;
	return (words);
}

/* 
ALLOCATE A STRING - Allocate a string, populate and null terminate.

Return - Allocated string or NULL in case of not enough mem
Params - 'len' is the length not including '\0'

61. Allocate mem
63. Populate string
69. Null terminate
70. Return string
*/
static char	*stralloc(int len, char *str)
{
	char	*dst;
	char	*ptr;
	int		i;

	i = 0;
	dst = (char *) malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	ptr = dst;
	while (i < len)
	{
		*ptr = *str;
		i++;
		ptr++;
		str++;
	}
	*ptr = '\0';
	return (dst);
}

/* 
STRING LENGTH - Finds the length of the string until it finds 'c' or the end.

Return - Length of the string
Params - 's' being the string to iterate and 'c' the separator
*/
static int	strclen(char *str, char c)
{
	int		len;

	len = 0;
	while (*str != c)
	{
		if (*str == '\0')
			break ;
		len++;
		str++;
	}
	return (len);
}
