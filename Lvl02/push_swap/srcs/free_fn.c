/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:37:58 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/06 18:45:37 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
+ Free a linked list and set content to 0.*/
void	free_list(t_list *head)
{
	t_list	*temp;

	if (head->next == NULL)
	{
		free (head);
		head = NULL;
	}
	else
	{
		temp = head->next;
		free_list(temp);
	}
	free(head->next);
}
/* 
+ Free the allocated arr of str.*/
void    free_split(char **arr)
{
    int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
