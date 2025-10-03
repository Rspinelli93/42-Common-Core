/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 23:43:29 by rick              #+#    #+#             */
/*   Updated: 2025/10/03 15:00:05 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
    long    nb;

    nb = n;
    if (nb == -2147483648)
    {
        ft_putstr_fd("-2147483648", fd);
        return ;
    }
    if (nb < 0)
    {
        ft_putchar_fd('-', fd);
        nb *= -1;
        ft_putnbr_fd(n, fd);
    }
    if (nb > 9)
    {
        ft_putnbr_fd((nb / 10), fd);
        ft_putnbr_fd((nb % 10), fd);
    }
    if (nb < 10)
        ft_putchar_fd(n + '0', fd);
}