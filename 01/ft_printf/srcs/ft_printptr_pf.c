/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:06:13 by rick              #+#    #+#             */
/*   Updated: 2025/10/08 20:39:11 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printptr_pf(void *ptr, char *str, int *cnt)
{
    unsigned long u;

    u = (unsigned long)ptr;
    if (u > 16)
	{
		ft_printhex_pf(u / 16, str, cnt);
		ft_printhex_pf(u % 16, str, cnt);
	}
	if (u < 16)
		ft_putchar_pf(str[u], cnt);
}
