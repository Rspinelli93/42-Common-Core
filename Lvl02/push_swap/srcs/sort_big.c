/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:36:07 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/10 16:50:15 by rspinell         ###   ########.fr       */
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
		cheapest_to_top(a, b, 1, 2);
		push_top(a, b, 2);
	}

	// ft_printf("END OF FIRST LOOP -----------\n\n\n");
	sort_three(a);
	while (*b)
	{
		update_values_b(a, b);
		cheapest_to_top(b, a, 1, 2);
		push_top(b, a, 1);
	}
	while (!is_sorted(a))
	{
		if (find_min_max(a, 1)->media)
			reverse_rotate(a, 1);
		else
			rotate(a, 1);
	}
}

/*
+ This function takes the cheapest node and its target to the top
+ of it's respective list, depending on its positions according to
+ if media == true or false, and their indexes.*/
void	cheapest_to_top(t_list **src, t_list **dst, int x, int y)
{
	t_list	*chp;
	t_list	*tar;

	chp = get_cheapest(src);
	tar = chp->targ;
	if (chp->media && tar->media)
	{
		// ft_printf("--------\n");
		// print_list(*src);
		// ft_printf("--------\n");
		// print_list(*dst);
		to_top_media(src, dst, x, y);
	}
	else if (!chp->media && !tar->media)
	{
		// ft_printf("--------\n");
		// print_list(*src);
		// ft_printf("--------\n");
		// print_list(*dst);
		to_top_index(src, dst, x, y);
	}
	else
	{
		// ft_printf("--------\n");
		// print_list(*src);
		// ft_printf("--------\n");
		// print_list(*dst);
		to_top(src, dst, x, y);
	}
	set_index_media(src);
	set_index_media(dst);
}

/*
+ Helper function to push top in case both media == TRUE.*/
void	to_top_media(t_list **src, t_list **dst, int x, int y)
{
	t_list	*chp;
	t_list	*tar;

	chp = get_cheapest(src);
	tar = chp->targ;
	while (*src != chp && *dst != tar)
		reverse_rotate_both(src, dst);
	while (*src != chp)
		reverse_rotate(src, x);
	while (*dst != tar)
		reverse_rotate(dst, y);
}

/*
+ Helper function to push top in case both media == FALSE.*/
void	to_top_index(t_list **src, t_list **dst, int x, int y)
{
	t_list	*chp;
	t_list	*tar;

	chp = get_cheapest(src);
	tar = chp->targ;
	while (*src != chp && *dst != tar)
		rotate_both(src, dst);
	while (*src != chp)
		rotate(src, x);
	while (*dst != tar)
		rotate(dst, y);
}

/*
+ For the rest of the cases.*/
void	to_top(t_list **src, t_list **dst, int x, int y)
{
	t_list	*chp;
	t_list	*tar;

	chp = get_cheapest(src);
	tar = chp->targ;
	if (chp->media)
	{
		while (*src != chp)
			reverse_rotate(src, x);
	}
	else if (!chp->media)
	{
		while (*src != chp)
			rotate(src, x);
	}
	if (tar->media)
	{
		while (*dst != tar)
			reverse_rotate(dst, y);
	}
	else if (!tar->media)
	{
		while (*dst != tar)
			rotate(dst, y);
	}
}
