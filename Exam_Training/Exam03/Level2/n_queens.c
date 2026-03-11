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
- N-QUEENS
* Goal: Place N queens on a board so none can attack each other.
* Function: Tries placing a queen column by column. For each column, it checks
* every row. If a spot is safe (no shared row or diagonal), it places the queen
* and recursively moves to the next column. When it reaches the end, it prints.

+ OCEANO TO THE RESCUE: https://www.youtube.com/watch?v=CcufXAmNU2I
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

/*
* Returns an absolute value of a number.*/
int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

/*
* This function takes as params:
+ board: sorting the data of all the positions of the previously placed queens
+ current_col: The column we are trying to place the queen right now
+ row: The specific row we are testing.

- Iterates over the board until arriving to the current_col (no need to check after, those are empty)
- Then we check:
	* board[i] = is it at the exact same spot?
	* ft_abs(board[i] - row) == (current_col - i) = check diagonals
		* ft_abs(board[i] - row) calculates the vertical distance.
		* current_col - i = calculates the horizontal distance
		* If both are equal, it means they are in diagonal.
- Then we increment to check the next queen.*/
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

/*
* BASE CASE:
+ if current_col == n, the algo succesfully placed all the queens, so you just print.

* RECURSIVE CASE:
+ This case tries to place a queen in every possible row (from 0 till n - 1)
+ if (is_safe) it records the placement in the board[current_col]
+ calls itself again to tackle the next column (current_col + 1)
*/
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
