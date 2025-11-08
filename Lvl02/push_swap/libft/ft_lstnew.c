/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:50:55 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/08 18:52:28 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
+ This function allocates memory for a new element of type t_list, setting its 
+ content to be the content parameter, and setting the next variable to NULL.

+ Then it returns the newly allocated / created element of the list. */
t_list	*ft_lstnew(int content)
{
	t_list	*li;

	li = malloc(sizeof(t_list));
	if (!li)
		return (NULL);
	li->cont = content;
	li->index = 0;
	li->media = 0;
	li->cheapest = 0;
	li->next = NULL;
	li->target_node = NULL;
	return (li);
}
