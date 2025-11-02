/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:56:57 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/02 16:13:12 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
+ This function iterates over the whole list and applies the 
+ function f to the content of each elements. */
void	ft_lstiter(t_list *lst, void (*f)(int))
{
	while (lst)
	{
		f(lst->cont);
		lst = lst->next;
	}
}
