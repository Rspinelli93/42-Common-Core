/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:34:26 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/07 19:54:29 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
+ Function to sort 3 numbers
+ It works always within the same stack*/
void	sort_three(t_list **hd)
{
	t_list	*s;

	s = (*hd)->next;
	if (((*hd)->cont < s->cont) && (s->cont < ft_lstlast((*hd))->cont))
		return ;
	else if (((*hd)->cont > s->cont) && (s->cont > ft_lstlast((*hd))->cont))
	{
		swap_ab(hd);
		shift_down(hd);
	}
	else if (((*hd)->cont > s->cont) && (s->cont < ft_lstlast((*hd))->cont))
	{
		if (ft_lstlast((*hd))->cont > (*hd)->cont)
			swap_ab(hd);
		else
			shift_up(hd);
	}
	else
	{
		shift_down(hd);
		s = (*hd)->next;
		if ((*hd)->cont > s->cont)
			swap_ab(hd);
	}
}

/*
+ Sort 2 nodes.*/
void	sort_two(t_list **list)
{
	if ((*list)->cont > (*list)->next->cont)
	{
		swap_ab(list);
	}
}
