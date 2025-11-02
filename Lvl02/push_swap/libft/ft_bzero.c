/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 21:11:14 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/02 15:21:46 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
+ Erases the data in the n bytes of the memory starting at the
+ location pointed to by s, by writing zeros (bytes containing '\0') to that area. */
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
