/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:24:17 by rick              #+#    #+#             */
/*   Updated: 2025/11/23 23:15:31 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **get_map(char	adress)
{
 	int 	fd;
	char	**str;

	fd = open(adress, O_RDONLY);
 	str = get_next_line(fd);
	ft_printf("%s", str);
	close(fd);
}

void	free_map(char **str)
{
	free(str);
}

int	get_size(char *adress)
{
	int 	fd;
	int		cnt;
	char	c;
	int		rd;

	cnt = 0;
	rd = 1;
	fd = open(adress, O_RDONLY);
	while (rd != 0)
	{
		rd = read(fd, &c, 1);
		if (c != '\n')
			cnt++;
	}
	close(fd);
	return (cnt);
}

void	map_parser(void);
/* 
Key Concepts:

*    File Reading: Read the map file line by line.
*    Validation: Ensure the map is rectangular and properly formatted.
*    Storing the Map: Store the map in a 2D array for easy access.
*/

//void read_map(const char *filename, t_game *game);
/*
    Purpose: Reads the map file and populates the game’s map array.
    Implementation Tips:

    Open the file using open().
    Read each line using get_next_line() or similar.
    Check that each line is the same length.
    Count the number of player starts (P), exits (E), and collectibles (C).
    Ensure the map is surrounded by walls (1).
    */
/*
Map Validation Checklist:

    Map is rectangular.
    Map is enclosed by walls.
    Contains exactly one player start (P).
    Contains at least one exit (E).
    Contains at least one collectible (C).*/