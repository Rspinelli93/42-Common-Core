/*
*Assignment name  : add_prime_sum
*Expected files   : add_prime_sum.c
*Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

#include <stdio.h>
#include <unistd.h>

int     is_prime(int num);
int     ft_atoi(char* str);
void    ft_putnbr(int num);
void    ft_putchar(char c);

int main(int argc, char** argv)
{
    int num;
    int res;
    
    res = 0;
    num = 0;
    if (argc != 2)
    {
        write(1, "0\n", 2);
        return (1);
    }
    num = ft_atoi(argv[1]);
    if (num < 1)
    {
        write(1, "0\n", 2);
        return (1);
    }
    while (num > 0)
    {
        if (is_prime(num))
            res += num;
        num--;
    }
    ft_putnbr(res);
    write(1, "\n", 1);
    return (0);
}

// int main(void)
// {
//     ft_putnbr(5);
// }

void    ft_putnbr(int num)
{
    if (num > 9)
    {
        ft_putnbr(num / 10);
        ft_putnbr(num % 10);
    }
    if (num < 10)
        ft_putchar(num + 48);
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

// int main(void)
// {
//     printf("%i", is_prime(5));
// }

int     is_prime(int num)
{
    int cnt;
    int n;

    n = num;
    cnt = 0;
    if (num < 2)
        return (0);
    while (n > 1)
    {
        if ((num % n) == 0)
            cnt++;
        n--;
    }
    if (cnt == 1)
        return (1);
    return (0);
}

// int main(void)
// {
//     printf("%i", ft_atoi("520"));
// }

int     ft_atoi(char* str)
{
    int sign;
    int num;

    sign = 1;
    num = 0;
    while ((*str >= 8 && *str <= 13) || *str == ' ')
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= 48 && *str <= 57)
    {
        num = (num * 10) + (*str - 48);
        str++;
    }
    return (num * sign);
}