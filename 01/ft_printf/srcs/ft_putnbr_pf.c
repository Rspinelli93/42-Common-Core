/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:07:45 by rick              #+#    #+#             */
/*   Updated: 2025/10/12 10:56:19 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_pf(int i, int *cnt)
{
	long	nb;

	nb = i;
	if (nb == -2147483648)
	{
		ft_putstr_pf("-2147483648", cnt);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar_pf('-', cnt);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr_pf((nb / 10), cnt);
		ft_putnbr_pf((nb % 10), cnt);
	}
	if (nb < 10)
	{
		ft_putchar_pf(nb + '0', cnt);
	}
}
/*int main(void)
{
	int i = 42;
	ft_putnbr_pf(i, &i);
	printf("\nExpected opt: 42\nCount expt: 44. Res: %i\n", i);
	return (0);
}*/
