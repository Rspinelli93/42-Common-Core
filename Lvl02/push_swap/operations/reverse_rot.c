/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:03:17 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/10 18:01:17 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
+ Reverse rotate: Shift down all elements of stack a by 1.
+ The last element becomes the first one.
+ int val = 0 for no printing.*/
void	rra(t_list **list, int x)
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
	ft_printf("rra\n");
}

/*
+ Reverse rotate b: Shift down all elements of stack a by 1.
+ The last element becomes the first one.
+ int val = 0 for no printing.*/
void	rrb(t_list **list, int x)
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
	ft_printf("rrb\n");
}

/*
+ rrr : (rotate reverse a) and (rotate reverse b) at the same time.
+ The last element becomes the first one.*/
void	rrr(t_list **a, t_list **b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_printf("rrr\n");
}
