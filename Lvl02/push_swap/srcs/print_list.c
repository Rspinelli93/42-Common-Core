/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:52:28 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/05 11:00:55 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
+ Prints the content of each node with a \n after.*/
void	print_list(t_list *head)
{
	while (head)
	{
		ft_printf("%i\n", head->cont);
		head = head->next;
	}
}
