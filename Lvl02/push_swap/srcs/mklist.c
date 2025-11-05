/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mklist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:29:26 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/05 10:43:05 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
+ This function takes an array and creates a linked list
+ allocating each node and setting the content of each 
+ node to each number of each possition in the array.
+
+ The return value is a pointer to the first node.*/
t_list	*mklist(int ac, char **arr)
{
	int		i;
	t_list	*head;

	i = 2;
	head = ft_lstnew(ft_atoi(arr[1]));
	while (i < ac)
	{
		ft_lstadd_back(&head, ft_lstnew(ft_atoi(arr[i])));
		i++;
	}
	return (head);
}
