/*
Assignment name  : permutations
Expected files   : *.c *.h
Allowed functions: puts, malloc, calloc, realloc, free, write
---------------------------------------------------------------

Write a program that will print all the permutations of a string given as argument.

The solutions must be given in alphabetical order.

We will not try your program with strings containing duplicates (eg: 'abccd').

For example this should work:

$> ./permutations a | cat -e
a$

$> ./permutations ab | cat -e
ab$
ba$

$> ./permutations abc | cat -e
abc$
acb$
bac$
bca$
cab$
cba$
*/

#include <unistd.h>
#include <stdlib.h>

/*
- 2. PERMUTATIONS
* Goal: Print all possible combinations of a string's letters in alphabetical order.
* Function: Sorts the string first. It builds a new word letter by letter using an 
* array to track which letters are already "used". When the new word reaches the 
* original length, it prints it, then backtracks to try different letters.
*/

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	sort_str(char *str, int len)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (str[j] > str[j + 1])
			{
				tmp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	solve(char *str, int len, char *buffer, int *used, int step)
{
	int	i;

	if (step == len)
	{
		buffer[step] = '\0';
		write(1, buffer, len);
		write(1, "\n", 1);
		return ;
	}
	i = 0;
	while (i < len)
	{
		if (used[i] == 0)
		{
			used[i] = 1;
			buffer[step] = str[i];
			solve(str, len, buffer, used, step + 1);
			used[i] = 0;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int		len;
	char	*buffer;
	int		*used;
	int		i;

	if (ac == 2)
	{
		len = ft_strlen(av[1]);
		buffer = malloc(sizeof(char) * (len + 1));
		used = malloc(sizeof(int) * len);
		if (!buffer || !used)
			return (1);
		i = 0;
		while (i < len)
			used[i++] = 0;
		sort_str(av[1], len);
		solve(av[1], len, buffer, used, 0);
		free(buffer);
		free(used);
	}
	return (0);
}
