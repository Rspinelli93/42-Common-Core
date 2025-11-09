/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:34:26 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/09 15:17:27 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
+ Function to sort 3 numbers
+ It works always within the same stack*/
void	sort_three(t_list **list)
{
	t_list	*s;

	s = (*list)->next;
	if (((*list)->cont < s->cont) && (s->cont < ft_lstlast((*list))->cont))
		return ;
	else if (((*list)->cont > s->cont) && (s->cont > ft_lstlast((*list))->cont))
	{
		swap_ab(list, 1);
		reverse_rotate(list, 1);
	}
	else if (((*list)->cont > s->cont) && (s->cont < ft_lstlast((*list))->cont))
	{
		if (ft_lstlast((*list))->cont > (*list)->cont)
			swap_ab(list, 1);
		else
			rotate(list, 1);
	}
	else
	{
		reverse_rotate(list, 1);
		s = (*list)->next;
		if ((*list)->cont > s->cont)
			swap_ab(list, 1);
	}
}

/*
+ Sort 2 nodes.*/
void	sort_two(t_list **list)
{
	if ((*list)->cont > (*list)->next->cont)
	{
		swap_ab(list, 1);
	}
}
