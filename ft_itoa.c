/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 23:34:10 by rick              #+#    #+#             */
/*   Updated: 2025/10/02 22:49:01 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cntdigits(int n);
static char	*ifzero(void);
static char	*mincase(void);

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == 0)
		return (ifzero());
	if (n == -2147483648)
		return (mincase());
	i = cntdigits(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

// COUNT DIGITS
static int	cntdigits(int n)
{
	int	dig;

	dig = 0;
	if (n < 0)
	{
		dig++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		dig++;
	}
	return (dig);
}

// HANDLE CASE ZERO
static char	*ifzero(void)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

// HANDLE MIN_INT
static char	*mincase(void)
{
	char	*str;
	int		i;
	long	min;

	i = 10;
	min = 2147483648;
	str = malloc(sizeof(char) * 12);
	if (!str)
		return (NULL);
	str[0] = '-';
	str[11] = '\0';
	while (min > 0)
	{
		str[i--] = (min % 10) + '0';
		min /= 10;
	}
	return (str);
}
