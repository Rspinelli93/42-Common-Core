/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:57:31 by rspinell          #+#    #+#             */
/*   Updated: 2025/10/04 17:27:12 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
Iterates through the list ’lst’, applies the
function ’f’ to each node’s content, and creates
a new list resulting of the successive applications
of the function ’f’.  The ’del’ function is used to
delete the content of a node if needed.

This functions copies a list, setting the content
of the new elements to f(oldelement.content).

Return the first element of new list.

45. create new
46. lst++
47. store the beggining in strt
WHILE LOOP:
50. iterate until *lst == NULL
52. create new temp with ft_lstnew node 
    and set the content to f(lst->content)
53. set new->next to temp
54. set new = new->next
55. lst = lst->next
56. clear temp
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	t_list	*strt;

	if (!lst || !f || !del)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	lst = lst->next;
	strt = new;
	while (lst == NULL)
	{
		temp = ft_lstnew(f(lst->content));
		new->next = temp;
		new = new->next;
		lst = lst->next;
		del(temp->content);
		free(temp);
	}
	return (strt);
}
