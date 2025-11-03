/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:02:34 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/03 19:15:06 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
+ ra (rotate a): Shift up all elements of stack a by 1.
+ The first element becomes the last one. */
void	shift_up(t_list **head)
{
	t_list	*node;

	if (!*head)
		return ;
	node = *head;
	*head = (*head)->next;
	ft_lstadd_back(head, node);
}
