/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 23:28:50 by rick              #+#    #+#             */
/*   Updated: 2025/10/01 20:35:31 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*dst;
	char	*res;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *) malloc(sizeof(char) * len);
	if (!res)
		return (NULL);
	ptr = (char *) s1;
	dst = res;
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
	return (res);
}