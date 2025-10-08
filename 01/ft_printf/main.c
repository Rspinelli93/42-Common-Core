/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 21:47:05 by rick              #+#    #+#             */
/*   Updated: 2025/10/08 22:01:18 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	main(void)
{
	int	i = -42;
	unsigned int u = 42;
	char *str = "This is a string";
	ft_printf("Integer: %i\n", &i);
//	ft_printf("Decimal: %i\n", &i);
//	ft_printf("Hexa: %x\n", &i);
//	ft_printf("HEXA: %X\n", &i);
//	ft_printf("Pointer: %p\n", i);
//	ft_printf("Char: %i\n", *str);
//	ft_printf("String: %i\n", str);
//	ft_printf("Percentage: %%\n");
//	ft_printf("Unsigned %u\n", u);
	return (0);
}