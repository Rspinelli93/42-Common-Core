/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 23:32:15 by rick              #+#    #+#             */
/*   Updated: 2025/10/06 11:10:32 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*skipc(char *str, char c);
static int	cntwords(char *s, char c);
static char	*strmake(int len, char *str);
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
		arr[i] = strmake(strclen(str, c), str);
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

words = word count
alt = switch, so we will only add to the words count
	if alt == 0

83. iterate over the string
89. add to count in posisitive cases
94. set alt to 0 again
40. Return the word
*/

static int	cntwords(char *s, char c)
{
	int	words;
	int alt;

	words = 0;
	alt = 0;
	while (*s)
	{
		if (*s != c && alt == 0)
		{
			alt = 1;
			words++;
		}
		else if (*s == c)
			alt = 0;
		s++;
	}
	return (words);
}

/*
MAKE A STRING - Allocate a string, populate and null terminate.

Return - Allocated string or NULL in case of not enough mem
Params - 'len' is the length not including '\0'

61. Allocate mem
63. Populate string
69. Null terminate
70. Return string
*/
static char	*strmake(int len, char *str)
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
