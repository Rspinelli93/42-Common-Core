/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:37:58 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/09 12:18:21 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
+ Free a linked list and set content to 0.*/
void	free_list(t_list *list)
{
	t_list	*temp;

	if (list->next == NULL)
	{
		free (list);
		list = NULL;
	}
	else
	{
		temp = list->next;
		free_list(temp);
	}
	free(list->next);
}

/* 
+ Free the allocated arr of str.*/
void	free_split(char **arr)
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
