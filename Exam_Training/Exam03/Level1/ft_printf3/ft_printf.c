/*
Assignment name  : ft_printf
Expected files   : ft_printf.c
Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
--------------------------------------------------------------------------------

Write a function named `ft_printf` that will mimic the real printf with the following constraints:

- It will manage only the following conversions: s,d, and x

Your function must be declared as follows:

int ft_printf(const char *, ... );

Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
To test your program compare your results with the true printf.

Your function must not leak.


Exemples of the function output:

call: ft_printf("Hello %s\n", "toto");
out:Hello toto$

call: ft_printf("Magic %s is %d", "number", 42);
out:Magic number is 42%

call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
out:Hexadecimal for 42 is 2a$

Warning: Your function must not have any leaks, this will be checked during moulinette
*/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

void ft_putchar(char c, int *ret)
{
	write(1, &c, 1);
	*ret += 1;
}

void ft_putstr(char *str, int *ret)
{
	while (*str)
	{
		ft_putchar(*str, ret);
		str++;
	}
}

void ft_putnbr(int num, int *ret)
{
	if (num == INT_MIN)
	{
		write(1, "-2147483648", 12);
		*ret += 12;
		return ;
	}
	if (num < 0)
	{
		ft_putchar('-', ret);
		ft_putnbr((num * -1), ret);
	}
	if (num > 9)
	{
		ft_putnbr(num / 10, ret);
		ft_putnbr(num % 10, ret);
	}
	if (num < 10 && num > -1)
		ft_putchar(num + '0', ret);
}

void ft_puthex(unsigned int num, int *ret)
{
	char *hex = "0123456789abcdef";

	if (num > 15)
	{
		ft_putnbr(num / 16, ret);
		ft_putnbr(num % 16, ret);
	}
	if (num < 16)
		ft_putchar(hex[num], ret);
}

void separator(char c, int *ret, va_list *args)
{
	if (c == 'd')
		ft_putnbr(va_arg(*args, int), ret);
	if (c == 'x')
		ft_putnbr(va_arg(*args, unsigned int), ret);
	if (c == 's')
		ft_putstr(va_arg(*args, char *), ret);
}

int ft_printf(const char *format, ... )
{
	int ret = 0;
	int i = 0;
	va_list args;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			separator(format[i], &ret, &args);
		}
		else
		{
			ft_putchar(format[i], &ret);
		}
		i++;
	}
	return (ret);
}

int main(void)
{
	// ft_printf("%s\n", "hola");
	// ft_printf("%x\n", 42);
	// ft_printf("%d\n", INT_MIN);
	// ft_printf("%d\n", 0);
	ft_printf("%d\n", -450);
	// int i = ft_printf("%d\n", INT_MAX);
	// ft_printf("%x\n", i);
	return (0);
}
