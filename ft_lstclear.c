/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:56:16 by rspinell          #+#    #+#             */
/*   Updated: 2025/10/03 22:22:53 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
This functions works similarly as the ft_lstdelone function, 
but instead of removing only one element, it removes the element 
passed as parameter as well as all the following elements. 
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(tmp, del);
		*lst = tmp;
	}
	free(*lst);
	*lst = NULL;
}
