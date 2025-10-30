/*
*Assignment name  : ft_range
*Expected files   : ft_range.c
*Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int len = 0;
	int ms = 0;
	int end = 1;
	int start = -3;

	if (end > start)
	{
		//caso 1
		ms = start;
		while (ms <= end)
		{
			ms++;
			len++;
		}
	}
	if (start > end)
	{
		//caso 2
		ms = end;
		while (ms <= start)
		{
			ms++;
			len++;
		}
	}
	int *arr = malloc (len);
	int i = 0;
	if (end > start)
	{
		//caso 1
		while (start <= end)
		{
			arr[i] = start;
			start++;
			i++;
		}
	}
	else
	{
		//caso 2
		while (end <= start)
		{
			arr[i] = end;
			end++;
			i++;
		}
	}
	i = 0;
	while (i < len)
	{
		printf("%i", arr[i]);
		i++;
	}
	return (0);
}
