/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:02:45 by rick              #+#    #+#             */
/*   Updated: 2025/11/07 19:52:44 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_atoi(char *str);
static int	is_repeated(int size, char **arr);

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
		if (!is_atoi(arr[i])
			|| ft_atoi(arr[i]) < -2147483648
			|| ft_atoi(arr[i]) > 2147483647)
		{
			ft_printf("ERROR ARGS");
			return (0);
		}
		i++;
	}
	if (is_repeated(size, arr))
	{
		ft_printf("ERROR ARGS");
		return (0);
	}
	return (1);
}

/*
+ Bool. Checks if the string fullfils the conditions for atoi*/
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

/*
+ Checks for a repeated number in the args*/
static int	is_repeated(int size, char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size - 1)
		{
			if (ft_atoi(arr[i]) == ft_atoi(arr[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
