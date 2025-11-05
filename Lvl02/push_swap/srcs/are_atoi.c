/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:02:45 by rick              #+#    #+#             */
/*   Updated: 2025/11/05 11:00:09 by rspinell         ###   ########.fr       */
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
	int	i;

	if (size < 2)
		return (0);
	i = 1;
	while (i < size)
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
	if (ft_isdigit(*str))
		return (1);
	return (0);
}
