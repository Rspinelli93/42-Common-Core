/*
Assignment name  : powerset
Expected files   : *.c *.h
Allowed functions: atoi, printf, fprintf, malloc, calloc, realloc, free, stdout,
write
--------------------------------------------------------------------------------

Write a program that will take as argument an integer n followed by a set s of
distinct integers.
Your program should display all the subsets of s whose sum of elements is n.

The order of the lines is not important, but the order of the elements in a subset is:
it must match the order in the initial set s.
This way, you should not have any duplicates (eg: '1 2' and '2 1').
For example, using the command ./powerset 5 1 2 3 4 5
this output is valid:
1 4
2 3
5
this one is also valid:
2 3
5
1 4
but not this one:
4 1
3 2
5


In case of a malloc error your program will exit with the code 1.

We will not test with invalid sets (for example '1 1 2').

Hint: the empty subset is a valid subset of any set. It will be displayed as an empty line.

For example this should work:
$> ./powerset 3 1 0 2 4 5 3 | cat -e
3$
0 3$
1 2$
1 0 2$
$> ./powerset 12 5 2 1 8 4 3 7 11 | cat -e
8 4$
1 11$
1 4 7$
1 8 3$
2 3 7$
5 7$
5 4 3$
5 2 1 4$
$> ./powerset 0 1 -1 | cat -e
$
1 -1$
$> ./powerset 7 3 8 2 | cat -e

// Other tests:
$> ./powerset 100 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 | cat -e
...
$> ./powerset -1 1 2 3 4 5 -10 | cat -e
...
$> ./powerset 0 -1 1 2 3 -2 | cat -e
...
$> ./powerset 13 65 23 3 4 6 7 1 2 | cat -e
...
$> ./powerset 10 0 1 2 3 4 5 6 7 8 9 | cat -e
...
*/

#include <stdio.h>
#include <stdlib.h>

/*
- POWERSET
* Goal: Find all subsets from a list of numbers that add up to a target number.
* Function: Looks at each number in the list one by one and makes a binary choice:
* it recursively calls itself once INCLUDING the number in the sum, and once
* EXCLUDING it. If it reaches the end of the list and hits the target, it prints.
*/

/*
* Struct holding:
+ int *set: an array of the numbers starting from av[2]
+ int *subset: an empty array where I build the outputs.
+ int target: thats av[1], the sum we are aiming to reach
+ int len: total amount of numbers in set*/
typedef struct s_data
{
	int	*set;
	int	*subset;
	int	len;
	int	target;
}	t_data;

/*
* BASE CASE

+ if (idx == data->len) : have we reached the end of the array set? (say, we made a yes or no desition for each number)
+		if (current_sum == data->target) : Does the sum is equal to  the target?
+			print the numbers in subset separated by a space and new line at the end.

* RECURSIVE CASE
+ Put the number at the current position inside the subset
+ Rerun solve as the case where you keep the number (if it woesnt work is handled in the BASE CASE)
+ Rerun solve as the case where you dont keep the number
*/
void	solve(t_data *data, int idx, int sub_size, int current_sum)
{
	int	i;

	if (idx == data->len)
	{
		if (current_sum == data->target)
		{
			i = 0;
			while (i < sub_size)
			{
				printf("%d", data->subset[i]);
				if (i < sub_size - 1)
					printf(" ");
				i++;
			}
			printf("\n");
		}
		return ;
	}
	data->subset[sub_size] = data->set[idx];
	solve(data, idx + 1, sub_size + 1, current_sum + data->set[idx]);
	solve(data, idx + 1, sub_size, current_sum);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	if (ac >= 2)
	{
		data.target = atoi(av[1]);
		data.len = ac - 2;
		data.set = malloc(sizeof(int) * (data.len + 1));
		data.subset = malloc(sizeof(int) * (data.len + 1));
		if (!data.set || !data.subset)
			return (1);
		i = 0;
		while (i < data.len)
		{
			data.set[i] = atoi(av[i + 2]);
			i++;
		}
		solve(&data, 0, 0, 0);
		free(data.set);
		free(data.subset);
	}
	return (0);
}
