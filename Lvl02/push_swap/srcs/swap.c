/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 12:23:45 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/09 15:24:14 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
+ sa/sb (swap a or b): Swap the first 2 elements at the top of stack a or b.
+ Do nothing if there is only one element or none.
+ int val prints: 1 = sa, 2 = sb, 0 = for double swap*/
void	swap_ab(t_list **list, int x)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*temp;

	if (!*list || !(*list)->next)
		return ;
	node1 = *list;
	node2 = node1->next;
	temp = node2->next;
	node2->next = node1;
	node1->next = temp;
	*list = node2;
	if (!x)
		return ;
	if (x == 1)
		ft_printf("sa\n");
	if (x == 2)
		ft_printf("sb\n");
}

/*
+ ss : (swap a) and (swap b) at the same time. 
+ prints "ss"*/
void	swap_both(t_list **a, t_list **b)
{
	swap_ab(a, 0);
	swap_ab(b, 0);
	ft_printf("ss\n");
}
