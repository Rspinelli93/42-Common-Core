/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 21:43:11 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/10 22:11:31 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
+ This function takes the cheapest node and its target to the top
+ of it's respective list, depending on its positions according to
+ if media == true or false, and their indexes.*/
void	cheapest_to_top_b(t_list **b, t_list **a)
{
	t_list	*chp;
	t_list	*tar;

	chp = get_cheapest(b);
	tar = chp->targ;
	if (chp->media && tar->media)
		btoa_bot(b, a);
	else if (!chp->media && !tar->media)
		btoa_top(b, a);
	else
		btoa(b, a);
	set_index_media(b);
	set_index_media(a);
}

/*
+ Helper function to push top in case both media == TRUE.*/
void	btoa_bot(t_list **b, t_list **a)
{
	t_list	*chp;
	t_list	*tar;

	chp = get_cheapest(b);
	tar = chp->targ;
	while (*b != chp && *a != tar)
		rrr(b, a);
	while (*b != chp)
		rrb(b, 1);
	while (*a != tar)
		rra(a, 1);
}

/*
+ Helper function to push top in case both media == FALSE.*/
void	btoa_top(t_list **b, t_list **a)
{
	t_list	*chp;
	t_list	*tar;

	chp = get_cheapest(b);
	tar = chp->targ;
	while (*b != chp && *a != tar)
		rr(b, a);
	while (*b != chp)
		rb(b, 1);
	while (*a != tar)
		ra(a, 1);
}

/*
+ For the rest of the cases.*/
void	btoa(t_list **b, t_list **a)
{
	t_list	*chp;
	t_list	*tar;

	chp = get_cheapest(b);
	tar = chp->targ;
	if (chp->media)
	{
		while (*b != chp)
			rrb(b, 1);
	}
	else if (!chp->media)
	{
		while (*b != chp)
			rb(b, 1);
	}
	if (tar->media)
	{
		while (*a != tar)
			rra(a, 1);
	}
	else if (!tar->media)
	{
		while (*a != tar)
			ra(a, 1);
	}
}
