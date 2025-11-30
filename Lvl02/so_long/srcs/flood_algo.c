/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:09:14 by rick              #+#    #+#             */
/*   Updated: 2025/11/30 11:42:27 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Boolean function to check if player, coin or exit 
are blocked.*/
int	is_blocked(char *address)
{
	t_map	*dup;

	dup = map_dup(address);
	if (!dup)
		return (ft_printf("Error\nMap alloc"), 1);
	flood_map(dup, dup->p1_x, dup->p1_y);
	if (no_c(dup->arr, 'C') && no_c(dup->arr, 'E'))
		return (free_map(dup), 0);
	return (free_map(dup), 1);
}

/*
Flood algo logic, it will recursively paint the tiles
with 'F' values till all possible tiles are painted with
an F and we reach all the possible walls.*/
void	flood_map(t_map *dup, int x, int y)
{
	if (y < 0 || x < 0)
		return ;
	if (dup->arr[y][x] == '1' || dup->arr[y][x] == 'F')
		return ;
	dup->arr[y][x] = 'F';
	flood_map(dup, x + 1, y);
	flood_map(dup, x - 1, y);
	flood_map(dup, x, y + 1);
	flood_map(dup, x, y - 1);
}

/*
Function to allocate a second map to be able to modify
it's contents safely with the flood algorithm.*/
t_map	*map_dup(char *adress)
{
	int		fd;
	t_map	*map;

	fd = open(adress, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		return (ft_printf("Error\nMap alloc"), NULL);
	set_size(adress, map);
	if (map->size == 0)
		return (free(map), NULL);
	map->arr = ft_calloc(sizeof(char *), (map->size + 1));
	if (!map->arr)
		return (free(map), NULL);
	map->arr = set_array(map, fd);
	if (!map->arr)
		return (free_map(map), NULL);
	init_p_pos(map, map->arr);
	init_e_pos(map, map->arr);
	return (map);
}
