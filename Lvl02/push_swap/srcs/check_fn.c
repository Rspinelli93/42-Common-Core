/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:02:45 by rick              #+#    #+#             */
/*   Updated: 2025/11/06 18:51:16 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_atoi(char *str);

/*
+ Bool: Checker function to know if all numbers 
+ and argument count is valid. Print error message
+ also.*/
int	are_atoi(int size, char **arr)
{
	int		i;

	i = 0;
	while (i < size - 1)
	{
		if (is_atoi(arr[i]) == 0)
		{
			ft_printf("ERROR ARGS");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	is_atoi(char *str)
{
	while ((*str >= 9 && *str <= 13)
		|| *str == 32)
	{
		str++;
	}
	if ((*str == '+') || (*str == '-'))
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
/*
+ Bool. Check if the list is in order.*/
int	is_sorted(t_list **list)
{
    t_list	*temp;

	temp = *list;
	while (temp->next)
	{
		if (temp->cont > temp->next->cont)
			return (0);
		temp = temp->next;
	}
	return (1);
}
