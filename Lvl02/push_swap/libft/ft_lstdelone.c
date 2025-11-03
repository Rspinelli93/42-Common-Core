/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:55:23 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/03 19:08:22 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
+ This function takes a list element as parameter 
+ and deletes its content as well as free the allocated 
+ memory using the del function passed as parameter too. */
void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	del(lst->cont);
	free(lst);
}
