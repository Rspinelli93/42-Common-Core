/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:45:48 by rick              #+#    #+#             */
/*   Updated: 2025/11/30 11:24:34 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
map_parser runs all the functions for parsing the map
if all the conditions are met it returns 1, otherwise
will return 0.*/
int	map_parser(char **arr, t_map *map, char *address)
{
	if (!is_rectangular(arr))
		return (0);
	if (!find_sprite(arr, 'P'))
		return (0);
	if (!find_sprite(arr, 'E'))
		return (0);
	if (!find_sprite(arr, 'C'))
		return (0);
	if (!is_closed(arr, map))
		return (0);
	if (is_blocked(address))
		return (ft_printf("Error\nPlayer, Collec or Exit blocked\n"), 0);
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
			ft_printf("Error\nMap is not rectangular, not valid\n");
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
		return (ft_printf("Error\nMap needs 1 consumable (min)\n"), 0);
	if (c == 'P' && count != 1)
		return (ft_printf("Error\nMap needs 1 player (only)\n"), 0);
	if (c == 'E' && count != 1)
		return (ft_printf("Error\nMap needs 1 exit (only)\n"), 0);
	return (1);
}

/*
This function will check for empty lines or for the map missing
a block of wall at least on the edges.
In case conditions are not met, it will print an error message and
retutn false, otherwise will return true.*/
int	is_closed(char **arr, t_map *map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (i < map->size && arr[i])
	{
		len = ft_strlen(arr[i]);
		if (len > 0 && arr[i][len - 1] == '\n')
			len--;
		if (len == 0)
			return (ft_printf("Error\nEmpty line detected\n"), 0);
		if (arr[i][0] != '1' || arr[i][len - 1] != '1')
			return (ft_printf("Error\nMap sides not closed\n"), 0);
		if (i == 0 || arr[i + 1] == NULL)
		{
			j = 0;
			while (j < len)
				if (arr[i][j++] != '1')
					return (ft_printf("Error\nMap top/bot not closed\n"), 0);
		}
		i++;
	}
	return (1);
}
