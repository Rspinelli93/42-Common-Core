/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:56:57 by rspinell          #+#    #+#             */
/*   Updated: 2025/10/03 22:23:33 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
This function iterates over 
the whole list and applies the function f 
to the content of each elements. 
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst->next != NULL)
	{
		f(lst);
		lst = lst->next;
	}
	f(lst);
}
