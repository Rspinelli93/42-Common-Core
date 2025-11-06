/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 12:23:45 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/06 18:48:36 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
+ sa/sb (swap a or b): Swap the first 2 elements at the top of stack a or b.
+ Do nothing if there is only one element or none.*/
void	swap_ab(t_list **head)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*temp;

	if (!*head || !(*head)->next)
		return ;
	node1 = *head;
	node2 = node1->next;
	temp = node2->next;
	node2->next = node1;
	node1->next = temp;
	*head = node2;
	ft_printf("sa\n");
}
/*
+ ss : (swap a) and (swap b) at the same time. */
void	swap_both(t_list **head_a, t_list **head_b)
{
	swap_ab(head_a);
	swap_ab(head_b);
	ft_printf("ss\n");
}
