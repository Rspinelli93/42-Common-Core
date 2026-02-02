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

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

void ft_putchar(char c, int *cnt)
{
    write(1, &c, 1);
    *cnt += 1;
}

void ft_putstr(char *str, int *cnt)
{
    if (!str)
    {
        write(1, "(null)" ,6);
        *cnt = *cnt + 6;
    }
    else 
    {
        while (*str)
        {
            ft_putchar(*str, cnt);
            str++;
        }
    }
}

void ft_putnbr(int num, int *cnt)
{
    if (num == INT_MIN)
    {
        ft_putstr("-2147483648", cnt);
        return ;
    }
    if (num < 0)
    {
		ft_putchar('-', cnt);
        num *= -1;
    }
    if (num > 9)
    {
        ft_putnbr(num / 10, cnt);
        ft_putnbr(num % 10, cnt);
    }
    else
    {
        ft_putchar(num + '0', cnt);
    }
}

void ft_printhex(unsigned int num, char *hex, int *cnt)
{
    if (num > 15)
    {
        ft_printhex(num / 16, hex, cnt);
        ft_printhex(num % 16, hex, cnt);
    }
    else
        ft_putchar(hex[num], cnt);
}

int ft_printf(const char *format, ...)
{
    char        *str = (char *)format;
    va_list     args;
    int         cnt = 0;

    va_start(args, format);
    while (*str)
    {
        if (*str == '%' && *(str + 1) != '\0')
        {
            str++;
            if (*str == 's')
                ft_putstr(va_arg(args, char *), &cnt);
            if (*str == 'x')
                ft_printhex(va_arg(args, unsigned int), "0123456789abcdef", &cnt);
            if (*str == 'd')
                ft_putnbr(va_arg(args, int), &cnt);
            str++;
        }
        else
        {
            ft_putchar(*str, &cnt);
            str++;
        }
    }
    va_end(args);
    return (cnt);
}

int main(void)
{
    printf("%i", ft_printf("%d\n", INT_MIN));
    return (0);
}