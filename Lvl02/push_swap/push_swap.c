/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:35:41 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/09 15:57:21 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//* cc ./push_swap.c ./push_swaplib.a -I ./includes -o test

#include "push_swap.h"
#include "string.h"

static void	sort_list(t_list **a, t_list **b);

int	main(int argc, char **argv)
{
	t_list	*la;
	t_list	*lb;
	char	**arr;

	la = NULL;
	lb = NULL;
	if (argc < 2)
		return (-1);
	if (argc == 2)
		arr = ft_split(argv[1], ' ');
	else
		arr = &argv[1];
	if (!are_atoi(argc, arr))
		return (-1);
	la = mklist(argc, arr);
	sort_list(&la, &lb);
	print_list(la);
	ft_lstclear(&la);
	if (argc == 2)
		free_split(arr);
	return (0);
}

static void	sort_list(t_list **a, t_list **b)
{
	if (!is_sorted(a))
	{
		if (ft_lstsize(*a) == 2)
			sort_two(a);
		else if (ft_lstsize(*a) == 3)
			sort_three(a);
		else
			sort_big(a, b);
	}
}

//* find length of stack
//* free stack
//* free split
//* find last node
//* find min and max node
//* include limits.h
//* handle limits
// handle print erro for firsr if check
//* handle same number
// Control mklist() - Make sure to propperly
//		initialize all the elements of each node
//* Handle printing propper command when using each command (if a or b)
