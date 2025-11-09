/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_targets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:23:13 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/09 12:25:00 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* TESTED
+ Find the closest smaller (if pushing from a to b)
+ If closest smaller not found, targer node is the max value.*/
void	set_target_atob(t_list **a, t_list **b)
{
	t_list	*pa;
	t_list	*pb;
	t_list	*temp;

	if (!*a || !*b)
		return ;
	pa = *a;
	while (pa)
	{
		pb = *b;
		temp = find_min_max(b, 0);
		while (pb)
		{
			if (pb->cont < pa->cont && pb->cont > temp->cont)
				temp = pb;
			pb = pb->next;
		}
		if (pa->cont < temp->cont)
			pa->targ = find_min_max(b, 1);
		else
			pa->targ = temp;
		pa = pa->next;
	}
}

/* TESTED
+ Find the closest bigger (if pushing from b to a)
+ If closest bigger not found, targer node is the min value */
void	set_target_btoa(t_list **b, t_list **a)
{
	t_list	*pa;
	t_list	*pb;
	t_list	*temp;

	if (!*a || !*b)
		return ;
	pb = *b;
	while (pb)
	{
		pa = *a;
		temp = find_min_max(a, 1);
		while (pa)
		{
			if (pa->cont > pb->cont && pa->cont < temp->cont)
				temp = pa;
			pa = pa->next;
		}
		if (pb->cont > temp->cont)
			pb->targ = find_min_max(a, 0);
		else
			pb->targ = temp;
		pb = pb->next;
	}
}
