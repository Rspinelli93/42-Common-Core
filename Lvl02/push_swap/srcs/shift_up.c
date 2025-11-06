/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:02:34 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/06 18:48:14 by rick             ###   ########.fr       */
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
/*
+ rr : (rotate a) and (rotate b) at the same time.
+ The first element becomes the last one.*/
void	shift_up_both(t_list **head1, t_list **head2)
{
	shift_up(head1);
	shift_up(head2);
	ft_printf("rr\n");
}
