/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:37:58 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/05 12:39:56 by rspinell         ###   ########.fr       */
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
