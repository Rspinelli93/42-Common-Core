/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:35:41 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/11 20:08:11 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//* cc ./push_swap.c ./push_swaplib.a -I ./includes -o test

#include "push_swap.h"
#include "string.h"

static char	**parser(int ac, char **av);
static int	arr_size(char **arr);

int	main(int argc, char **argv)
{
	t_list	*la;
	t_list	*lb;
	char	**arr;

	la = NULL;
	lb = NULL;
	if (argc < 2)
		return (-1);
	arr = parser(argc, argv);
	if (!arr)
		return (-1);
	la = mklist(argc, arr);
	sort_list(&la, &lb);
	print_list(la);
	ft_lstclear(&la);
	if (argc == 2)
		free_split(arr);
	return (0);
}

/*
+ Pretty self explicatory the name.*/
static char	**parser(int ac, char **av)
{
	char	**arr;

	if (ac == 2)
	{
		arr = ft_split(av[1], ' ');
		if (!arr)
			return (NULL);
		if (!are_atoi(arr_size(arr), arr))
		{
			free_split(arr);
			return (NULL);
		}
	}
	else
	{
		arr = &av[1];
		if (!are_atoi(ac, arr))
			return (NULL);
	}
	return (arr);
}

/*
+ To get the right number in case of split.*/
static int	arr_size(char **arr)
{
	char	**ptr;
	int		size;

	size = 1;
	ptr = arr;
	while (*ptr)
	{
		size++;
		ptr++;
	}
	return (size);
}

//* find length of stack
//* free stack
//* free split
//* find last node
//* find min and max node
//* include limits.h
//* handle limits
//* handle print erro for firsr if check
//* handle same number
//* Control mklist() - Make sure to propperly
//		*initialize all the elements of each node
//* Handle printing propper command when using each command (if a or b)
// handle same number at split
// hadle biggest or smallest int at split
// handle letters at split "s 6 7 8 34"
// handle minus and plus sign "5 8 9 - 3 4"
// handle 1 number "4"