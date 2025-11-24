/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:33:03 by rick              #+#    #+#             */
/*   Updated: 2025/11/24 12:10:22 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Loading Textures and Images

Your game will be more engaging with visuals! Load images for your player,
         walls, collectibles, and exit.
Key Concepts:

    Image Loading: Use mlx_xpm_file_to_image() to load XPM files.
    Storing Images: Keep references to your images for rendering.

Loading Images:

game->img_player = mlx_xpm_file_to_image(game->mlx_ptr, "assets/player.xpm",
         &width, &height);

    Parameters:
    game->mlx_ptr: The MinilibX connection.
    "assets/player.xpm": Path to your image file.
    &width, &height: To retrieve image dimensions.

Tips:

    Check Image Loading: Ensure that the image pointers are not NULL.
    Uniform Tile Size: Make sure all your images are the same dimensions.

*/
