/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:08:50 by rick              #+#    #+#             */
/*   Updated: 2025/10/09 15:00:22 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhex_pf(unsigned int u, char *str, int *cnt)
{
	if (u > 16)
	{
		ft_printhex_pf(u / 16, str, cnt);
		ft_printhex_pf(u % 16, str, cnt);
	}
	if (u < 16)
		ft_putchar_pf(str[u], cnt);
}

/* int main (void)
{
	unsigned int	num = 123;
	char	*str = "0123456789abcdefg";
	int		count = 41;
	ft_printhex_pf(num, str, &count);
	printf("Num 123, expected print: 7b\nCount expected 42. Res: %i\n", count);
	return (0);
}
 */