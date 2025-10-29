/*
*Assignment name  : tab_mult
*Expected files   : tab_mult.c
*Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>*/

#include <unistd.h>
#include <stdio.h>
#include <limits.h>

long	ft_atoi(char *str);
void	ft_putnbr(long num);

int	main(int argc, char** argv)
{
	long	num;
	long	mult;

	mult = 1;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	num = ft_atoi(argv[1]);
	if (num < 1 || num * 9 > INT_MAX)
	{
		write(1, "\n", 1);
		return (1);
	}
	while (mult < 10)
	{
		ft_putnbr(mult);
		write(1, " x ", 3);
		ft_putnbr(num);
		write(1, " = ", 3);
		ft_putnbr(mult * num);
		write(1, "\n", 1);
		mult++;
	}
	return (0);
}

// int main (void)
// {
// 	printf("%i", ft_atoi("-50"));
// }
long	ft_atoi(char *str)
{
	long num;
	long sign;

	sign = 1;
	num = 0;
	if (!str)
		return (0);
	while ((*str >= 8 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
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

// int	main(void)
// {
// 	ft_putnbr(150);
// }

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_putnbr(long num)
{
	if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	if (num < 10)
	{
		ft_putchar(num + 48);
	}
}