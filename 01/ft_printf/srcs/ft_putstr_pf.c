/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:02:37 by rick              #+#    #+#             */
/*   Updated: 2025/10/12 10:56:18 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_pf(char *str, int *cnt)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write (1, "(null)", 6);
		*cnt = *cnt + 6;
	}
	else
	{
		while (str[i] != '\0')
		{
			ft_putchar_pf(str[i], cnt);
			i++;
		}
	}
}
/*int main(void)
{
	int i = 42;
	char *str = "Hola";
	ft_putstr_pf(str, &i);
	printf("\nExpected opt: Hola\nCount expt: 46. Res: %i\n", i);
	return (0);
}*/
