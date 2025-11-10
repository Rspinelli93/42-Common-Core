/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:36:23 by rick              #+#    #+#             */
/*   Updated: 2025/11/10 21:01:23 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* TESTED
+ Prints the content of each node with a \n after.
 		if (list->targ)
			ft_printf("target: %i\n", list->targ->cont);
		ft_printf("index: %i - media: %i\n", list->index, list->media);
		ft_printf("cost: %i\n", list->cost);
		ft_printf("cheapest: %i\n", list->cheapest);
		ft_printf("\n"); */
void	print_list(t_list *list)
{
	while (list)
	{
		ft_printf("%i\n", list->cont);
		list = list->next;
	}
}

/* TESTED
+ Return a pointer to the max or min cont node
+ Use 1 for max and 0 for min.*/
t_list	*find_min_max(t_list **list, const int a)
{
	t_list	*ptr;
	t_list	*temp;

	ptr = *list;
	temp = *list;
	if (a == 1)
	{
		while (temp)
		{
			if (ptr->cont < temp->cont)
				ptr = temp;
			temp = temp->next;
		}
		return (ptr);
	}
	else
	{
		while (temp)
		{
			if (ptr->cont > temp->cont)
				ptr = temp;
			temp = temp->next;
		}
		return (ptr);
	}
}

/* TESTED
+ Set the index and the media for each node of the list
+ ft_printf("index: %i - media: %i",ptr->index, ptr->media);
*/
void	set_index_media(t_list **list)
{
	int		i;
	int		med;
	t_list	*ptr;

	med = ft_lstsize(*list) / 2;
	i = 0;
	if (!*list)
		return ;
	ptr = *list;
	while (ptr)
	{
		ptr->index = i;
		if (i < med)
			ptr->media = 0;
		else
			ptr->media = 1;
		i++;
		ptr = ptr->next;
	}
}

/*
+ Simple function to update values on each iteration. */
void	update_values_a(t_list **a, t_list **b)
{
	set_index_media(a);
	set_target_atob(a, b);
	set_cost_all(a);
	set_cheapest(a);
}

/*
+ Simple function to update values on each iteration. */
void	update_values_b(t_list **a, t_list **b)
{
	set_index_media(b);
	set_target_btoa(b, a);
	set_cost_all(b);
	set_cheapest(b);
}
