/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:57:31 by rspinell          #+#    #+#             */
/*   Updated: 2025/10/03 22:26:31 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
This functions works similarly as the ft_lstiter function, 
but it creates a new list resulting of the successive applications of f 
on each element's content. 
*/

/*
. check if lst or f or del is NULL
. count elements
. create new empty list
. add the new values in order
. free the old one
. return new list
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *newl;
    int     size;
    int     i;

    i = 0;
    size = ft_lstsize(lst);
    if (!lst || !f || !del)
        return (NULL);
    while (i < size)
    {
        ft_lstiter(*newl, f)
    }
}
