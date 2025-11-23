/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:24:17 by rick              #+#    #+#             */
/*   Updated: 2025/11/23 10:35:32 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	map_parser();
/*
Map Validation Checklist:

    Map is rectangular.
    Map is enclosed by walls.
    Contains exactly one player start (P).
    Contains at least one exit (E).
    Contains at least one collectible (C).*/