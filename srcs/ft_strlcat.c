/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:26:24 by rspinell          #+#    #+#             */
/*   Updated: 2025/09/29 16:26:30 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	char	*ptr;
	size_t	slen;

	ptr = (char *)src;
	slen = (size_t)(ft_strlen(dst) + ft_strlen(src));
	while(*dst != '\0')
	{
		dst++;
		dsize--;
	}
	while (dsize > 1 && *ptr)
	{
		*dst = *ptr;
		dst++;
		ptr++;
		dsize--;
	}
	*dst = '\0';
	return (slen);
}
