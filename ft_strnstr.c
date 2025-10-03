/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:26:50 by rspinell          #+#    #+#             */
/*   Updated: 2025/10/03 18:23:50 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Search for a complete substring in max len characters.

28. Check if the sub is empty
*/

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s2[0])
		return ((char *) s1);
	while (s1[i] && i < len)
	{
		while ((s1[i + j] == s2[j]) && (s1[i + j] && i + j < len))
		{
			j++;
			if (!s2[j])
				return ((char *) s1 + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
