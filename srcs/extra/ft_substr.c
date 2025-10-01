/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 23:26:02 by rick              #+#    #+#             */
/*   Updated: 2025/10/01 20:14:53 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pts;
	char	*dst;
	char	*ptd;
	size_t	i;

	i = 0;
	dst = (char *) malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		*dst = '\0';
		return (dst);
	}
	pts = (char *) s + start;
	ptd = dst;
	while (i < len && *pts)
	{
		*ptd = *pts;
		ptd++;
		pts++;
		i++;
	}
	*ptd = '\0';
	return (dst);
}
