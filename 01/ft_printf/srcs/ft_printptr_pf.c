/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:06:13 by rick              #+#    #+#             */
/*   Updated: 2025/10/12 10:56:17 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printhexlong_pf(unsigned long u, char *str, int *cnt)
{
	if (u > 15)
	{
		ft_printhexlong_pf(u / 16, str, cnt);
		ft_printhexlong_pf(u % 16, str, cnt);
	}
	if (u < 16)
		ft_putchar_pf(str[u], cnt);
}

void	ft_printptr_pf(void *ptr, char *str, int *cnt)
{
	unsigned long	u;

	if (!ptr)
	{
		ft_putstr_pf("(nil)", cnt);
		return ;
	}
	u = (unsigned long)ptr;
	ft_putstr_pf("0x", cnt);
	if (u > 15)
	{
		ft_printhexlong_pf(u / 16, str, cnt);
		ft_printhexlong_pf(u % 16, str, cnt);
	}
	if (u < 16)
		ft_putchar_pf(str[u], cnt);
}
/* int main (void)
{

	char	*str = "(nil)";
	int		count = 0;

	ft_putstr_pf(str, &count);
 	//ft_printptr_pf(&c, str, &count);
	ft_printf("\n%p\n", 0);
	int i = printf("%p", NULL);
	printf("%i", i);
	return (0);
} */
