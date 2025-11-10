/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:34:26 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/10 18:29:59 by rick             ###   ########.fr       */
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
