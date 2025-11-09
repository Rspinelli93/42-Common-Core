/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:36:07 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/09 15:59:40 by rspinell         ###   ########.fr       */
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
	if (ft_lstsize(*a) > 3)
		push_top(a, b, 2);
	if (ft_lstsize(*a) > 3)
		push_top(a, b, 2);
	while (ft_lstsize(*a) > 3)
	{
		update_values(a, b);
		cheapest_to_top(a, b, 1, 2);
		push_top(a, b, 2);
	}
	sort_three(a);
	while (*b)
	{
		update_values(a, b);
		cheapest_to_top(b, a, 2, 1);
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
+ Simple function to update values on each iteration. */
void	update_values(t_list **a, t_list **b)
{
	set_target_btoa(b, a);
	set_target_atob(a, b);
	set_index_media(a);
	set_index_media(b);
	set_cost_all(a);
	set_cost_all(b);
	set_cheapest(a);
	set_cheapest(b);
}


/* void	cheapest_to_top(t_list **src, t_list **dst, int x, int y)
{
	t_list	*chp = set_cheapest(src);
	t_list	*tar = chp->targ;

	while (*src != chp || *dst != tar)
	{
		if (chp->media && tar->media)
		{
			while (chp->next && tar->next)
				reverse_rotate_both(src, dst);
			while (chp->next)
				reverse_rotate(src, x);
			while (tar->next)
				reverse_rotate(dst, y);
			reverse_rotate_both(src, dst);
			set_index_media(src);
			set_index_media(dst);
		}
		else if (!chp->media && !tar->media)
		{
			while (chp->index && tar->index)
				rotate_both(src, dst);
			while (chp->index)
				rotate(src, x);
			while (tar->index)
				rotate(dst, y);
			rotate_both(src, dst);
			set_index_media(src);
			set_index_media(dst);
		}
		else
		{
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
			set_index_media(src);
			set_index_media(dst);
		}
	}
} */

/*
+ This function takes the cheapest node and its target to the top
+ of it's respective list, depending on its positions according to
+ if media == true or false, and their indexes.*/
void	cheapest_to_top(t_list **src, t_list **dst, int x, int y)
{
	t_list	*chp = set_cheapest(src);
	t_list	*tar = chp->targ;

	while (*src != chp || *dst != tar)
	{
		if (chp->media && tar->media)
            to_top_index(src, dst, x, y);
		else if (!chp->media && !tar->media)
            to_top_index(src, dst, x, y);
		else
            to_top(src, dst, x, y);
    }
}

/*
+ Helper function to push top in case both media == TRUE.*/
void	to_top_media(t_list **src, t_list **dst, int x, int y)
{
	t_list	*chp = set_cheapest(src);
	t_list	*tar = chp->targ;

    while (chp->next && tar->next)
        reverse_rotate_both(src, dst);
    while (chp->next)
        reverse_rotate(src, x);
    while (tar->next)
        reverse_rotate(dst, y);
    reverse_rotate_both(src, dst);
    set_index_media(src);
    set_index_media(dst);
}

/*
+ Helper function to push top in case both media == FALSE.*/
void	to_top_index(t_list **src, t_list **dst, int x, int y)
{
	t_list	*chp = set_cheapest(src);
	t_list	*tar = chp->targ;

    while (chp->index && tar->index)
        rotate_both(src, dst);
    while (chp->index)
        rotate(src, x);
    while (tar->index)
        rotate(dst, y);
    rotate_both(src, dst);
    set_index_media(src);
    set_index_media(dst);
}

/*
+ For the rest of the cases.*/
void	to_top(t_list **src, t_list **dst, int x, int y)
{
	t_list	*chp = set_cheapest(src);
	t_list	*tar = chp->targ;

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
    set_index_media(src);
    set_index_media(dst);
}