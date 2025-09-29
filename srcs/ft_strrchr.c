/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 21:12:47 by rspinell          #+#    #+#             */
/*   Updated: 2025/09/29 16:25:00 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	ptr = (char *)s;
	i = 0;
	while (*ptr)
	{
		ptr++;
		i++;
	}
	while (i > 0)
	{
		ptr--;
		if (*ptr == (char)c)
			return (ptr);
		i--;
	}
	ptr = NULL;
	return (ptr);
}
