/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:08:50 by rick              #+#    #+#             */
/*   Updated: 2025/10/08 20:36:32 by rick             ###   ########.fr       */
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
