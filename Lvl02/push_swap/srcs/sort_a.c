/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 21:44:12 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/11 18:57:45 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
+ This function takes the cheapest node and its target to the top
+ of it's respective list, depending on its positions according to
+ if media == true or false, and their indexes.*/
void	cheapest_to_top_a(t_list **a, t_list **b)
{
	t_list	*chp;
	t_list	*tar;

	chp = get_cheapest(a);
	tar = chp->targ;
	if (chp->media && tar->media)
		atob_bot(a, b);
	else if (!chp->media && !tar->media)
		atob_top(a, b);
	else
		atob(a, b);
	set_index_media(a);
	set_index_media(b);
}

/*
+ Helper function to push top in case both media == TRUE.*/
void	atob_bot(t_list **a, t_list **b)
{
	t_list	*chp;
	t_list	*tar;

	chp = get_cheapest(a);
	tar = chp->targ;
	while (*a != chp && *b != tar)
		rrr(a, b);
	while (*a != chp)
		rra(a, 1);
	while (*b != tar)
		rrb(b, 1);
}

/*
+ Helper function to push top in case both media == FALSE.*/
void	atob_top(t_list **a, t_list **b)
{
	t_list	*chp;
	t_list	*tar;

	chp = get_cheapest(a);
	tar = chp->targ;
	while (*a != chp && *b != tar)
		rr(a, b);
	while (*a != chp)
		ra(a, 1);
	while (*b != tar)
		rb(b, 1);
}

/*
+ For the rest of the cases.*/
void	atob(t_list **a, t_list **b)
{
	t_list	*chp;
	t_list	*tar;

	chp = get_cheapest(a);
	tar = chp->targ;
	if (chp->media)
	{
		while (*a != chp)
			rra(a, 1);
	}
	else if (!chp->media)
	{
		while (*a != chp)
			ra(a, 1);
	}
	if (tar->media)
	{
		while (*b != tar)
			rrb(b, 1);
	}
	else if (!tar->media)
	{
		while (*b != tar)
			rb(b, 1);
	}
}
