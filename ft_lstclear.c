/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:56:16 by rspinell          #+#    #+#             */
/*   Updated: 2025/10/03 21:11:06 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*tmp;

	if (!lst)
		return ;
	ptr = *lst;
	while (ptr != NULL)
	{
		tmp = ptr;
		ptr = ptr->next;
		ft_lstdelone(tmp, del);
	}
	lst = NULL;
}
