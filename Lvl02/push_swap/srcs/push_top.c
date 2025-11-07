/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 12:31:51 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/07 18:12:45 by rspinell         ###   ########.fr       */
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

	if (!*h_srcs)
		return ;
	node1 = *h_srcs;
	*h_srcs = (*h_srcs)->next;
	ft_lstadd_front(h_dest, node1);
	ft_printf("pa\n");
}
