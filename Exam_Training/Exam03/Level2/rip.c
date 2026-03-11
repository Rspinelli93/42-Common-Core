/*
Assignment name  : rip
Expected files   : *.c *.h
Allowed functions: puts, write
--------------------------------------------------------------------------------

Write a program that will take as argument a string containing only parenthesis.
if the parenthesis are unbalanced (for example "())")
your program shall remove the minimum number of parentheses for the expression to be balanced.
By removing we mean replacing by spaces.
You will then print all the solutions (can be more than one).

The order of the solutions is not important.

For example this should work:
$> ./rip '(()' | cat -e
 ()$
( )$
$> ./rip '((()()())())' | cat -e
((()()())())$
$> ./rip '()())()'| cat -e
()() ()$
()( )()$
( ())()$
$> ./rip '(()(()(' | cat -e
(()  ) $
( )( ) $
( ) () $
 ()( ) $
*/

#include <stdio.h>

/*
- RIP
* Goal: Fix unbalanced parentheses by removing the absolute minimum amount needed.
* Function: First counts exactly how many extra '(' and ')' exist. Then, it goes
* through the string and recursively tries replacing them with spaces. Once it
* removes the exact target amount, it verifies if it is balanced and prints it.
*/

/*
+ Function to count if the string is ballanced or not.*/
int	is_balanced(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '(')
			count++;
		else if (str[i] == ')')
			count--;
		if (count < 0)
			return (0);
		i++;
	}
	return (count == 0);
}

/*
+ Function to know which one '(' or ')' needs to be removed from that string.
+ It will modifify the falues of the ints declared in main.*/
void	get_removals(char *str, int *left, int *right)
{
	int	i;

	i = 0;
	*left = 0;
	*right = 0;
	while (str[i])
	{
		if (str[i] == '(')
			(*left)++;
		else if (str[i] == ')')
		{
			if (*left > 0)
				(*left)--;
			else
				(*right)++;
		}
		i++;
	}
}

/*
* BASE CASE
+ If left and right are 0 and its balanced, print the string.

* RECURSIVE CASE
+ Decide which case to fix, either if we have more lefts or more rights

+ In either case, if you find a left or a right parenthesis char and you left or right is bigger than 0:
+ Change for a space, and run solve in i++ and -1 to that value (left or right)*/
void	solve(char *str, int start, int left, int right)
{
	int	i;

	if (left == 0 && right == 0)
	{
		if (is_balanced(str))
			puts(str);
		return ;
	}
	i = start;
	while (str[i])
	{
		if (left > 0 && str[i] == '(')
		{
			str[i] = ' ';
			solve(str, i + 1, left - 1, right);
			str[i] = '(';
		}
		else if (right > 0 && str[i] == ')')
		{
			str[i] = ' ';
			solve(str, i + 1, left, right - 1);
			str[i] = ')';
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	left;
	int	right;

	if (ac == 2)
	{
		get_removals(av[1], &left, &right);
		solve(av[1], 0, left, right);
	}
	return (0);
}
