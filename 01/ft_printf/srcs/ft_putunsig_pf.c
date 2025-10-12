/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsig_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 10:55:59 by rspinell          #+#    #+#             */
/*   Updated: 2025/10/12 11:02:13 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsig_pf(unsigned int u, int *cnt)
{
	unsigned long	ul;

	ul = (unsigned long)u;
	if (ul < 0)
	{
		ul = 4294967295 - ul;
	}
	if (ul > 9)
	{
		ft_putunsig_pf((ul / 10), cnt);
		ft_putunsig_pf((ul % 10), cnt);
	}
	if (ul < 10)
	{
		ft_putchar_pf(ul + '0', cnt);
	}
}
