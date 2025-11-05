/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:03:17 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/05 16:23:11 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
+ rra (reverse rotate a): Shift down all elements of stack a by 1.
+ The last element becomes the first one. */
void	shift_down(t_list **list)
{
	t_list	*new_start;
	t_list	*new_end;

	if (!*list)
		return ;
	new_start = ft_lstlast(*list);
	new_end = *list;
	while (new_end->next->next)
		new_end = new_end->next;
	ft_lstadd_front(list, new_start);
	new_end->next = NULL;
	ft_printf("rra\n");
}
