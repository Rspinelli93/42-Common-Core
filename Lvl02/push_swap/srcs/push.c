/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 12:31:51 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/09 12:41:37 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
+ push a node from src to dst
+ Do nothing if the srcs is empty
+ int val prints: 1 = pa, 2 = pb.
+ "pa"(1) = from b to a;
+ "pb"(2) = from a to b;*/
void	push_top(t_list **src, t_list **dst, int x)
{
	t_list	*node1;

	if (!*src)
		return ;
	node1 = *src;
	*src = (*src)->next;
	ft_lstadd_front(dst, node1);
	if (x == 1)
		ft_printf("pa\n");
	if (x == 2)
		ft_printf("pb\n");
}
