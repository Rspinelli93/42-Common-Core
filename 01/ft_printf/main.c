/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 21:47:05 by rick              #+#    #+#             */
/*   Updated: 2025/10/15 18:22:13 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	int	i = -42;
	unsigned int u = 42;
	char *str = "This is a string";
	ft_printf("Integer: %i\nDecimal: %i\nHexa: %x\nHEXA: %X\n", i, i, i, i);
	ft_printf("Pointer: %p\n", i);
	ft_printf("Char: %c\n", str[0]);
	ft_printf("String: %s\n", str);
	ft_printf("Percentage: %%\n");
	ft_printf("%u\n%u\n", -1, -2);
	return (0);
}