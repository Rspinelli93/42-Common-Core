/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:57:31 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/07 20:09:59 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
+ This functions copies a list, setting the content 
+ of the new elements to f(oldelement.content).
+
+ Iterates through the list ’lst’, applies the function ’f’ 
+ to each node’s content, and creates
+ a new list resulting of the successive applications 
+ of the function ’f’.  The ’del’ function is used to
+ delete the content of a node if needed.
+ [For more info, check original "libft" folder]*/
t_list	*ft_lstmap(t_list *lst, int (*f)(int))
{
	t_list	*new;
	t_list	*temp;
	int		val;

	if (!lst || !f)
		return (NULL);
	new = NULL;
	while (lst)
	{
		val = f(lst->cont);
		temp = ft_lstnew(val);
		if (!temp)
		{
			ft_lstclear(&new);
			return (NULL);
		}
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}
