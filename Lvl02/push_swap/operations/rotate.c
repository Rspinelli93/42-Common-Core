/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:02:34 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/09 16:03:45 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
+ Rotate: Shift up all elements of stack a by 1.
+ The first element becomes the last one.
+ int val prints: 1 = ra, 2 = rb, 0 = nothing.*/
void	rotate(t_list **list, int x)
{
	t_list	*node;

	if (!*list)
		return ;
	node = *list;
	*list = (*list)->next;
	ft_lstadd_back(list, node);
	if (x == 0)
		return ;
	if (x == 1)
		ft_printf("ra\n");
	if (x == 2)
		ft_printf("rb\n");
}

/*
+ rr : (rotate a) and (rotate b) at the same time.
+ The first element becomes the last one.*/
void	rotate_both(t_list **a, t_list **b)
{
	rotate(a, 0);
	rotate(b, 0);
	ft_printf("rr\n");
}
