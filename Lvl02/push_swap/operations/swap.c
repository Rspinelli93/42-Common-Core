/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 12:23:45 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/10 18:02:50 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
+ sa/sb (swap a or b): Swap the first 2 elements at the top of stack a or b.
+ Do nothing if there is only one element or none.
+ int val = 0 for no printing.*/
void	sa(t_list **list, int x)
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
	ft_printf("sa\n");
}

/*
+ sa/sb (swap a or b): Swap the first 2 elements at the top of stack a or b.
+ Do nothing if there is only one element or none.
+ int val = 0 for no printing.*/
void	sb(t_list **list, int x)
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
	ft_printf("sb\n");
}

/*
+ ss : (swap a) and (swap b) at the same time. 
+ prints "ss"*/
void	ss(t_list **a, t_list **b)
{
	sa(a, 0);
	sb(b, 0);
	ft_printf("ss\n");
}
