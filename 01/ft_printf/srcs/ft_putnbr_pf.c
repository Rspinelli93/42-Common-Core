/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:07:45 by rick              #+#    #+#             */
/*   Updated: 2025/10/07 22:00:29 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_pf(int i, int fd, int *cnt)
{
	long	nb;

	nb = i;
	if (nb == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		*cnt += 11;
		return ;
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr_fd((nb / 10), fd);
		ft_putnbr_fd((nb % 10), fd);
	}
	if (nb < 10)
	{
		ft_putchar_fd(nb + '0', fd);
		*cnt += 1;
	}
}
