/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:02:34 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/10 18:01:14 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
+ Rotate: Shift up all elements of stack a by 1.
+ The first element becomes the last one.
+ int val = 0 for no printing.*/
void	ra(t_list **list, int x)
{
	t_list	*node;

	if (!*list)
		return ;
	node = *list;
	*list = (*list)->next;
	ft_lstadd_back(list, node);
	if (x == 0)
		return ;
	ft_printf("ra\n");
}

/*
+ Rotate: Shift up all elements of stack a by 1.
+ The first element becomes the last one.
+ int val = 0 for no printing.*/
void	rb(t_list **list, int x)
{
	t_list	*node;

	if (!*list)
		return ;
	node = *list;
	*list = (*list)->next;
	ft_lstadd_back(list, node);
	if (x == 0)
		return ;
	ft_printf("rb\n");
}

/*
+ rr : (rotate a) and (rotate b) at the same time.
+ The first element becomes the last one.*/
void	rr(t_list **a, t_list **b)
{
	ra(a, 0);
	rb(b, 0);
	ft_printf("rr\n");
}
