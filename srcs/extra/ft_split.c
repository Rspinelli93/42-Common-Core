/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 23:32:15 by rick              #+#    #+#             */
/*   Updated: 2025/10/01 23:09:08 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Count words
int	cntwords(char *s, char c)
{
	int	words;

	words = 0;
	while (*s == c)
		s++;
	if (ft_strlen(s) == 0 || !s)
		return (0);
	while (s)
	{
		if (*s == c && *(s + 1) != c)
			words++;
		s++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{

}