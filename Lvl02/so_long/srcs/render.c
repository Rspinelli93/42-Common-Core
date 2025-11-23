/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:37:55 by rick              #+#    #+#             */
/*   Updated: 2025/11/23 19:06:54 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Step 5: Rendering the Game World

Now, let’s draw the map and all its elements onto the window.
Key Concepts:

    Rendering Loop: Continuously draw the current state of the game.
    Drawing Tiles: Place images on the window according to the map array.

Function to Render the Map:

void render_map(t_game *game);

Steps:

    Loop Through the Map Array:

    for (int y = 0; y < game->map_height; y++) 
        { for (int x = 0; x < game->map_width; x++) 
        { // Determine what to draw at (x, y) } }

    Determine Tile Type:

    '1': Wall.
    '0': Empty space.
    'P': Player.
    'C': Collectible.
    'E': Exit.

    Draw the Tile:

    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
        game->img_wall, x * tile_size, y * tile_size);

Tips:

    Redraw Every Frame: For simplicity, redraw the entire map each frame.
    Optimization: For better performance, only redraw what’s necessary.

 */
