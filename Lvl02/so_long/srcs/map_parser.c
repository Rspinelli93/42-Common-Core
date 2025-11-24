/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:45:48 by rick              #+#    #+#             */
/*   Updated: 2025/11/24 12:51:13 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
map_parser runs all the functions for parsing the map
if all the conditions are met it returns 1, otherwise
will return 0.*/
int	map_parser(char **arr)
{
	if (!is_rectangular(arr))
		return (0);
	if (!find_sprite(arr, 'P'))
		return (0);
	if (!find_sprite(arr, 'E'))
		return (0);
	if (!find_sprite(arr, 'C'))
		return (0);
	return (1);
}

/*
Checks if the map is rectangular by iterating on
each string of the arr and checking they have
the same length.
Return value is boolean 1 true or 0 for false.*/
int	is_rectangular(char	**arr)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(arr[i]);
	while (arr[i])
	{
		if (len != (int)ft_strlen(arr[i]))
		{
			ft_printf("Map is not rectangular, not valid\n");
			return (0);
		}
		i++;
	}
	return (1);
}

/*
Find sprite will search in the 2D array the char c.
In case of not validating the conditions, will print an error
message and return 0. If conditions are met, will just
return 1.*/
int	find_sprite(char **arr, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	if (c == 'C' && count < 1)
		return (ft_printf("Map needs 1 consumable (min)\n"), 0);
	if (c == 'P' && count != 1)
		return (ft_printf("Map needs 1 player (only)\n"), 0);
	if (c == 'E' && count != 1)
		return (ft_printf("Map needs 1 exit (only)\n"), 0);
	return (1);
}

int	is_blocked(char **arr, char c);
