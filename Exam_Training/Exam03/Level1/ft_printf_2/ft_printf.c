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

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

void    ft_putchar(char c, int *ret)
{
    write(1, &c, 1);
    *ret += 1;
}

void    ft_putstr(char *str, int *ret)
{
    while (str && *str)
    {
        ft_putchar(*str, ret);
        str++;
    }
}

void    ft_putnbr(int num, int *ret)
{
    long    nb;

    nb = num;
    if (nb == INT_MIN)
    {
        write(1, "-2147483648", 12);
        return ;
    }
    if (nb < 0)
    {
        ft_putchar('-', ret);
        ft_putnbr((nb * -1), ret);
    }
    if (nb > 9)
    {
        ft_putnbr(nb / 10, ret);
        ft_putnbr(nb % 10, ret);
    }
    if (nb < 10)
        ft_putchar(nb + '0', ret);
}

void    ft_puthex(unsigned int num, int *ret)
{
    char *hex = "0123456789abcdef";

    if (num > 15)
    {
        ft_puthex(num / 16, ret);
        ft_puthex(num % 16, ret);
    }
    if (num < 16)
        ft_putchar(hex[num], ret);
}

void    specifier(char c, int *ret, va_list *args)
{
    if (c == 's')
    {
        ft_putstr(va_arg(*args, char *), ret);   
    }
    if (c == 'd')
    {
        ft_putnbr(va_arg(*args, int), ret);   
    }
    if (c == 'x')
    {
        ft_puthex(va_arg(*args, unsigned int), ret);   
    }
}

int ft_printf(const char *str, ... )
{
    int     ret = 0;
    va_list  args;
    int     i = 0;
    
    va_start(args, str);
    while (str[i])
    {
        if (str[i] == '%' && str[i + 1] != '\0')
        {
            i++;
            specifier(str[i], &ret, &args);
            i++;
        }
        else
        {
            ft_putchar(str[i], &ret);
            i++;
        }
    }
    va_end(args);
    return (ret);
}

int main(void)
{
    ft_printf("Hola, esto funciona\n%s", "si funciona\n");
    int i = ft_printf("Hola\n%x\n", 42);
    ft_printf("%d\n", i);
    return (0);
}
