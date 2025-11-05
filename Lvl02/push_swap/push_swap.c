/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:35:41 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/05 17:55:24 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//* cc ./push_swap.c ./push_swaplib.a -I ./includes -o test

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*head_a;

	if (!are_atoi(argc, argv))
		return (-1);
	head_a = mklist(argc, argv);
	print_list(head_a);
	ft_printf("\n");
	if (argc == 4)
		sort_three(&head_a);
	print_list(head_a);
	ft_lstclear(&head_a, &del);
	return (0);
}

//* Step 1 pb pb pb pb …
//- Push every number exept 3 to stack b

//* Step 2 Sort 3 numbers

//* Step 3 Find the ”target node”
//- target node is the "smallest bigger"
//+ To find the smallest bigger, there are 2 conditions:
//+
//+ -- it’s bigger (in stack a) than the node we point at in b
//+ -- it’s the smallest one of those in stack a

//-  if the node in the stack is already the biggest one
//-  push it on top of the smallest number in stack a.

//* Step 4 Calculate “to top cost”
//+ want to make sure when we push the node from b to a, 
//+ it will be stored on top of the target node we have just calculated
//- That’s why we need to calculate the cost for the target node.
//+ how do I know if should use reverse rotate or rotate to bring the node to the top?
//- If it’s in the first half of the stack (index ≤ num of nodes / 2), rotate, or vice versa

//* Step 5 Find the “cheapest node”
//