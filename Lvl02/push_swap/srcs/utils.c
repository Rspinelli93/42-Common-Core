/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:36:23 by rick              #+#    #+#             */
/*   Updated: 2025/11/06 18:52:50 by rick             ###   ########.fr       */
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

	i = 1;
	head = ft_lstnew(ft_atoi(arr[0]));
	if (ac == 2)
	{
		while (arr[i])
		{
			ft_lstadd_back(&head, ft_lstnew(ft_atoi(arr[i])));
			i++;
		}
	}
	else
	{
		while (i < ac - 1)
		{
			ft_lstadd_back(&head, ft_lstnew(ft_atoi(arr[i])));
			i++;
		}
	}
	return (head);
}
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
t_list	*find_max(t_list **list);
t_list	*find_min(t_list **list);