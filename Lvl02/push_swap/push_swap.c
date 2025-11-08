/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:35:41 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/08 23:45:02 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//* cc ./push_swap.c ./push_swaplib.a -I ./includes -o test

#include "push_swap.h"
#include "string.h"

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;
	char	**arr;

	head_a = NULL;
	head_b = NULL;
	if (argc < 2)
		return (-1);
	if (argc == 2)
		arr = ft_split(argv[1], ' ');
	else
		arr = &argv[1];
	if (!are_atoi(argc, arr))
		return (-1);
	head_a = mklist(argc, arr);

	push_top(&head_a, &head_b);
	push_top(&head_a, &head_b);
	push_top(&head_a, &head_b);
	set_target_btoa(&head_b, &head_a);
	print_list(head_b);
	print_list(head_a);
	/*set_index_media(&head_a);
	if (!is_sorted(&head_a))
	{
		if (ft_lstsize(head_a) == 2)
			sort_three(&head_a);
		if (ft_lstsize(head_a) == 3)
			sort_three(&head_a);
	}
	print_list(head_a);
	ft_lstclear(&head_a);
	if (argc == 2)
		free_split(arr);*/
	return (0);
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