/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:56:16 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/07 18:29:58 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
+ This functions works similarly as the ft_lstdelone function,
+ but instead of removing only one element, it removes the element
+ passed as parameter as well as all the following elements.*/
void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst);
		*(lst) = tmp;
	}
	lst = NULL;
}
