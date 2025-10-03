/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:54:39 by rspinell          #+#    #+#             */
/*   Updated: 2025/10/03 22:21:32 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function lets us add a new element to the end of an existing list. */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!*lst)
		*lst = new;
	ptr = ft_lstlast(*lst);
	ptr->next = new;
	new->next = NULL;
}
