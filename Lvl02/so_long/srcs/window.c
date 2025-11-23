/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:31:36 by rick              #+#    #+#             */
/*   Updated: 2025/11/23 13:34:10 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


/*
Function to initialize the window.
mlx_init() && mlx_new_window() functions run malloc
therefore the correspondent malloc check.*/
int	win_init(t_data *data)
{
	data->conect = mlx_init();
	if (!data->conect)
		return (0);
	data->win = mlx_new_window(data->conect, 800, 600, "so_long");
	if (!data->win)
	{
		mlx_destroy_display(data->conect);
		free(data->conect);
		return (0);
	}
	return (1);
}


/*
*-------------------------------------------------------------------
 Initializing the Game Window with MinilibX

Key Concepts:

    MinilibX Initialization: Connect to the X-Window system.
    Window Creation: Create a window of appropriate size.

Steps:

    Initialize MinilibX:

    game->mlx_ptr = mlx_init();

    Create a New Window:

    game->win_ptr = mlx_new_window(game->mlx_ptr, width, height, "so_long");
    Width: tile_size * map_width.
    Height: tile_size * map_height.
    Tile Size: For example, 64 pixels.

Tips:

    Calculate Window Size Based on Map Dimensions.
    Check for Errors: Ensure that mlx_init() and mlx_new_window() return valid pointers.*/