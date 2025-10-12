/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:13:43 by rspinell          #+#    #+#             */
/*   Updated: 2025/10/12 11:04:39 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_specifier(int *cnt, char c, va_list *args);
/*
cc main.c -I includes -I libft libftprintf.a -o test

• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.
----------------------------------------
$) va_list: An object of type va_list is used by the
		macros va_start(3), va_arg(3), va_copy(3), and
		va_end(3) to traverse the list of arguments.
$) MACROS (func)
-	void va_start(va_list ap, last);
	"ap" is the list of args you create, and "last" is
	the last OF THE FIXED ONES, in this case "format";
	Defines which elements will or not vary.
	todo(run before the use of va_arg)
-	type va_arg(va_list ap, type);
	Allows access (IN ORDER) to the arguments of the variadic function.
	When called, move to the next argument - "type" is the type of variable
-	void va_copy(va_list dest, va_list src);
	Creates a duplicate of the argument list’s current position.
	That way: Keep one va_list (src) where it is.
	Use another (dest) to read the arguments without losing track.
-	void va_end(va_list ap);
	va_end() will free the allocated memory.
-------------------------------------------
$) IMPLEMENTATION
* Count args function int count_args(va_list args);
* Iterate until the end
* Make all functions for each letter
* Strncmp to check for flags
* Strcat to add the content to the string to print
*/

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		cnt;
	char	*str;

	cnt = 0;
	va_start(args, format);
	str = (char *)format;
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '\0')
		{
			str++;
			ft_specifier(&cnt, *str, &args);
			str++;
		}
		else
		{
			ft_putchar_pf(*str, &cnt);
			str++;
		}
	}
	va_end(args);
	return (cnt);
}

static void	ft_specifier(int *cnt, char c, va_list *args)
{
	if (c == 'c')
		ft_putchar_pf(va_arg(*args, int), cnt);
	if (c == 's')
		ft_putstr_pf(va_arg(*args, char *), cnt);
	if (c == 'p')
		ft_printptr_pf(va_arg(*args, void *), "0123456789abcdef", cnt);
	if (c == 'd')
		ft_putnbr_pf(va_arg(*args, int), cnt);
	if (c == 'i')
		ft_putnbr_pf(va_arg(*args, int), cnt);
	if (c == 'u')
		ft_putunsig_pf((int) va_arg(*args, unsigned int), cnt);
	if (c == 'x')
		ft_printhex_pf(va_arg(*args, unsigned int), "0123456789abcdef", cnt);
	if (c == 'X')
		ft_printhex_pf(va_arg(*args, unsigned int), "0123456789ABCDEF", cnt);
	if (c == '%')
		ft_putchar_pf('%', cnt);
}
/*
int	main(void)
{
	int	i = -42;
	unsigned int u = 42;
	char *str = "This is a string";
//	ft_printf("Integer: %i\nDecimal: %i\nHexa: %x\nHEXA: %X\n", i, i, i, i);
//	ft_printf("Pointer: %p\n", i);
//	ft_printf("Char: %c\n", str[0]);
//	ft_printf("String: %s\n", str);
//	ft_printf("Percentage: %%\n");
	ft_printf(" %X ", 16);
	return (0);
}*/
