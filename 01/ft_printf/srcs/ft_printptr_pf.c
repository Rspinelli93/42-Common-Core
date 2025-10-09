/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:06:13 by rick              #+#    #+#             */
/*   Updated: 2025/10/09 18:32:33 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_printptr_pf(void *ptr, char *str, int *cnt)
{
	unsigned long	u;

	u = (unsigned long)ptr;
	ft_putstr_pf("0x", cnt);
	if (u > 15)
	{
		ft_printhex_pf(u / 16, str, cnt);
		ft_printhex_pf(u % 16, str, cnt);
	}
	if (u < 16)
		ft_putchar_pf(str[u], cnt);
}
/*int main (void)
{
	char	c = '5';
	char	*str = "0123456789abcdefg";
	int		count = 41;
	ft_printptr_pf(&c, str, &count);
	printf("\nCount start: 41. Res: %i\n", count);
	return (0);
}*/
