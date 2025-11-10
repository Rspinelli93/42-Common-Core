/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:34:26 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/10 22:01:54 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
+ Function to sort 3 numbers
+ It works always within the same stack*/
void	sort_three(t_list **list)
{
	t_list	*biggest;

	biggest = find_min_max(list, 1);
	if (biggest == *list)
		ra(list, 1);
	else if ((*list)->next == biggest)
		rra(list, 1);
	if ((*list)->cont > (*list)->next->cont)
		sa(list, 1);
}

/*
+ Sort 2 nodes.*/
void	sort_two(t_list **list)
{
	if ((*list)->cont > (*list)->next->cont)
	{
		sa(list, 1);
	}
}

/*
+ Push 2 nodes only checking each time there are more than
+ 3 nodes in a_list.
+
+ Push nodes to b_list on top of their targets until you
+ have 3 nodes in a_list. (Always updating its values on
+ each iteration)
+
+ sort_three(a);
+
+ Push nodes to a_list on top of their targets until you
+ have no nodes in b_list. (Always updating its values on
+ each iteration)
+
+ In case needes, rotate or reverse rotate until is_sorted(a); */
void	sort_big(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) > 5 && !is_sorted(a))
		push_top(a, b, 2);
	if (ft_lstsize(*a) > 5 && !is_sorted(a))
		push_top(a, b, 2);
	while (ft_lstsize(*a) > 5 && !is_sorted(a))
	{
		update_values_a(a, b);
		cheapest_to_top_a(a, b);
		push_top(a, b, 2);
	}
	sort_five(a);
	while (*b)
	{
		update_values_b(a, b);
		cheapest_to_top_b(b, a);
		push_top(b, a, 1);
	}
	set_index_media(a);
	while (!is_sorted(a))
	{
		if (find_min_max(a, 1)->media)
			rra(a, 1);
		else
			ra(a, 1);
	}
}
