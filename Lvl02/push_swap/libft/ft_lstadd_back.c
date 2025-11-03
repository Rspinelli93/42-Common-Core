/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:54:39 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/03 14:35:41 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
+ This function lets us add a new element to the end of an existing list. */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	ptr = ft_lstlast(*lst);
	if (!ptr)
		*lst = new;
	else
	{
		ptr->next = new;
		new->next = NULL;
	}
}
