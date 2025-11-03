/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 12:31:51 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/03 19:18:06 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
+ pa (push a or b): Take the first element at the top 
+ of a/b and put it at the top of b/a.
+ Do nothing if the srcs is empty */
void	push_top(t_list **h_srcs, t_list **h_dest)
{
	t_list	*node1;
	t_list	*node2;

	if (!*h_srcs)
		return ;
	node1 = *h_srcs;
	node2 = *h_dest;
	if (!*h_dest)
		node2 = NULL;
	*h_srcs = (*h_srcs)->next;
	ft_lstadd_front(h_dest, node1);
}
