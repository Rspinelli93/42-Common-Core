/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:03:17 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/09 16:03:40 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
+ Reverse rotate: Shift down all elements of stack a by 1.
+ The last element becomes the first one.
+ int val prints: 1 = rra, 2 = rrb, 0 = nothing.*/
void	reverse_rotate(t_list **list, int x)
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
	if (x == 0)
		return ;
	if (x == 1)
		ft_printf("rra\n");
	if (x == 2)
		ft_printf("rrb\n");
}

/*
+ rrr : (rotate reverse a) and (rotate reverse b) at the same time.
+ The last element becomes the first one.*/
void	reverse_rotate_both(t_list **a, t_list **b)
{
	rotate(a, 0);
	rotate(b, 0);
	ft_printf("rrr\n");
}
