/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:36:07 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/10 18:34:02 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (ft_lstsize(*a) > 3 && !is_sorted(a))
		push_top(a, b, 2);
	if (ft_lstsize(*a) > 3 && !is_sorted(a))
		push_top(a, b, 2);
	while (ft_lstsize(*a) > 3 && !is_sorted(a))
	{
		update_values_a(a, b);
		cheapest_to_top_a(a, b);
		ft_printf("asd");
		push_top(b, a, 2);
	}
	ft_printf("END OF FIRST LOOP -----------\n\n\n");
	sort_three(a);
	while (*b)
	{
		update_values_b(a, b);
		cheapest_to_top_b(b, a);
		push_top(b, a, 1);
	}
	while (!is_sorted(a))
	{
		if (find_min_max(a, 1)->media)
			rra(a, 1);
		else
			ra(a, 1);
	}
}


//* ----------------------------------- //
//* ----------------------------------- //
//* ----------------------------------- //

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


//* ----------------------------------- //
//* ----------------------------------- //
//* ----------------------------------- //

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
