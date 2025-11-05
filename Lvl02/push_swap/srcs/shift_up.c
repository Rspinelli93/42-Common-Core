/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:02:34 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/05 15:02:40 by rspinell         ###   ########.fr       */
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
	ft_printf("ra\n");
}
