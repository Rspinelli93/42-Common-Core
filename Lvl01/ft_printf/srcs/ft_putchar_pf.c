/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 18:49:52 by rick              #+#    #+#             */
/*   Updated: 2025/10/12 10:47:40 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putchar_pf(char c, int *cnt)
{
	ft_putchar_fd(c, 1);
	*cnt += 1;
}
/*int	main(void)
{
	char c = 'x';
	int	cnt = 41;
	ft_putchar_pf(c, &cnt);
	printf("\nExpected print: 'x'\nExpected count 42. Res: %i\n", cnt);
	return (0);
}*/
