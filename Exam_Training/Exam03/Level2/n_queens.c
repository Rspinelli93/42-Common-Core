/* 
*Assignement name : n_queens

Expected files : *.c *.h

Allowed functions : atoi, fprintf, write, calloc, malloc, free, realloc, stdout, stderr

-------------------------------------------------------------------------

Write a program that will print all the solutions to the n queens problem
for a n given as argument.
We will not test with negative values.
The order of the solutions is not important.

You will display the solutions under the following format :
<p1> <p2> <p3> ... \n
where pn are the line index of the queen in each colum starting from 0.

For example this should work :
$> ./n_queens 2 | cat -e

$> ./n_queens 4 | cat -e
1 3 0 2$
2 0 3 1$

$> ./n_queens 7 | cat -e
0 2 4 6 1 3 5$
0 3 6 2 5 1 4$
etc... 
*/

#include <stdlib.h>
#include <unistd.h>

/* 
- 1. N-QUEENS
* Goal: Place N queens on a board so none can attack each other.
* Function: Tries placing a queen column by column. For each column, it checks
* every row. If a spot is safe (no shared row or diagonal), it places the queen 
* and recursively moves to the next column. When it reaches the end, it prints.
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	is_safe(int *board, int current_col, int row)
{
	int	i;

	i = 0;
	while (i < current_col)
	{
		if (board[i] == row || ft_abs(board[i] - row) == (current_col - i))
			return (0);
		i++;
	}
	return (1);
}

void	solve(int *board, int current_col, int n)
{
	int	row;
	int	i;

	if (current_col == n)
	{
		i = 0;
		while (i < n)
		{
			ft_putnbr(board[i]);
			if (i < n - 1)
				ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		return ;
	}
	row = 0;
	while (row < n)
	{
		if (is_safe(board, current_col, row))
		{
			board[current_col] = row;
			solve(board, current_col + 1, n);
		}
		row++;
	}
}

int	main(int argc, char **argv)
{
	int	n;
	int	*board;

	if (argc == 2)
	{
		n = atoi(argv[1]);
		if (n > 0)
		{
			board = (int *)malloc(sizeof(int) * n);
			if (!board)
				return (1);
			solve(board, 0, n);
			free(board);
		}
	}
	return (0);
}
