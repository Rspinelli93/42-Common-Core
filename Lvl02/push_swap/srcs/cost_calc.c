/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:08:26 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/09 13:23:57 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* TESTED
+ Search the cheapest cost node and set the value
+ of cheapest to true (1).
+ returns a pointer to it*/
t_list	*set_cheapest(t_list **list)
{
	t_list	*ptr;
	t_list	*temp;

	ptr = *list;
	temp = *list;
	while (temp)
	{
		if (ptr->cost > temp->cost)
			ptr = temp;
		temp = temp->next;
	}
	ptr->cheapest = 1;
	return (ptr);
}

/* TESTED
+ Calculate the cost of a node to be both itself
+ and it's target node on top of it's respective list.

- Calculate the number of moves needed:
- Math:
	X operations to bring a node to the top of 'a'
		.+
	X operations to bring this node target to top of 'b'
	= push cost;
*/
void	set_cost(t_list	**node, t_list **target, int med, int tmed)
{
	if (med && tmed)
	{
		if (ft_lstsize(*node) >= ft_lstsize(*target))
			(*node)->cost = ft_lstsize(*node) + 1;
		else
			(*node)->cost = ft_lstsize(*target) + 1;
	}
	else if (!med && !tmed)
	{
		if ((*node)->index >= (*target)->index)
			(*node)->cost = (*node)->index;
		else
			(*node)->cost = (*target)->index;
	}
	else
	{
		if (med)
			(*node)->cost += ft_lstsize(*node);
		else
			(*node)->cost += (*node)->index;
		if (tmed)
			(*node)->cost += ft_lstsize(*target);
		else
			(*node)->cost += (*target)->index;
	}
}

/*
+ Set the cost to all nodes of a list
! if node is in the middle there is a miss per 1 on cost. to see after*/
void	set_cost_all(t_list **list)
{
	t_list	*ptr;

	if (!*list)
		return ;
	ptr = *list;
	while (ptr)
	{
		set_cost(&(ptr), &(ptr->targ), ptr->media, ptr->targ->media);
		ptr = ptr->next;
	}
}
