/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 22:11:00 by rick              #+#    #+#             */
/*   Updated: 2025/11/17 13:56:12 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	ascii_to_bits(char c, int *arr)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		arr[i] = (c >> i) & 1;
		i++;
	}
}

char	bits_to_ascii(int *arr)
{
	int		i;
	char	c;
	int		mult;

	i = 0;
	mult = 1;
	c = 0;
	while (i < 8)
	{
		c += arr[i] * mult;
		mult *= 2;
		i++;
	}
	return (c);
}
