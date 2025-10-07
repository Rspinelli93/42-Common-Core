/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:13:43 by rspinell          #+#    #+#             */
/*   Updated: 2025/10/07 22:13:40 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_mode(int *cnt, char c, va_list args);

/*
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

	cnt = 0;
	va_start(args, format);
	while (format)
	{
		if (*format == '%')
		{
			format++;
			ft_mode(&cnt, *format, args);
			va_arg(args, type_of_var);
//! 		ACA HAY QUE ACLARAR LA VARIABLE, EN FTMODE AGREGAR UN PARAMETRO POINTER A ARGUMENTO, PARA PODER MODIFICARLO EN CADA FUNCION
			format++;
			continue ;
		}
		cnt++;
		format++;
	}
	va_end(args);
	return (cnt);
}

static void	ft_mode(int *cnt, char c, va_list args)
{
	if (c == 'c')
		ft_putchar_pf(va_arg(args, int), cnt);
	if (c == 's')
		ft_putstr_pf(va_arg(args, char *), cnt);
	if (c == 'p')
		ft_printptr_pf(va_arg(args, void *), cnt);
	if (c == 'd')
		ft_putnbr_pf(va_arg(args, int), 1, cnt);
	if (c == 'i')
		ft_putnbr_pf(va_arg(args, int), 1, cnt);
	if (c == 'u')
		ft_putunsig_pf(va_arg(args, unsigned int), cnt);
	if (c == 'x')
		ft_printhex_pf(va_arg(args, unsigned int), cnt);
	if (c == 'X')
		ft_printhexup_pf(va_arg(args, unsigned int), cnt);
	if (c == '%')
		ft_putchar_pf('%', cnt);
}
