/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 12:23:45 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/03 19:16:03 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
+ (swap a or b): Swap the first 2 elements at the top of stack a or b.
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
}
