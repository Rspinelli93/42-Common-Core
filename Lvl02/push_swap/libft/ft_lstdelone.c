/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:55:23 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/07 18:14:41 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
+ This function takes a list element as parameter 
+ and deletes its content as well as free the allocated 
+ memory using the del function passed as parameter too. */
void	ft_lstdelone(t_list *lst)
{
	free(lst);
}
