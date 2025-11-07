/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:03:17 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/07 19:53:24 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
+ rra (reverse rotate a): Shift down all elements of stack a by 1.
+ The last element becomes the first one. */
void	shift_down(t_list **list)
{
	t_list	*new_start;
	t_list	*new_end;

	if (!*list)
		return ;
	new_start = ft_lstlast(*list);
	new_end = *list;
	while (new_end->next->next)
		new_end = new_end->next;
	ft_lstadd_front(list, new_start);
	new_end->next = NULL;
	ft_printf("rra\n");
}

/*
+ rrr : (rotate reverse a) and (rotate reverse b) at the same time.
+ The last element becomes the first one.*/
void	shift_down_both(t_list **head1, t_list **head2)
{
	shift_down(head1);
	shift_down(head2);
	ft_printf("rrr\n");
}
