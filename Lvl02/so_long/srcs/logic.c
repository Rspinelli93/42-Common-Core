/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:41:11 by rick              #+#    #+#             */
/*   Updated: 2025/11/24 12:13:26 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* 
Step 7: Implementing Game Logic

Move the player, collect items, and check for game completion.
Key Concepts:

    Movement Logic: Check for walls before moving.
    Collectibles: Keep track of items collected.
    Win Condition: Allow exit only after all collectibles are gathered.

Moving the Player:

void move_player(t_game *game, int dx, int dy) {
    int new_x = game->player_x + dx;
    int new_y = game->player_y + dy;
    if (game->map[new_y][new_x] != '1') {
        game->player_x = new_x;
        game->player_y = new_y;
        // Check for collectibles or exit
    }
}

Collecting Items:

    When the player moves onto a tile with a 'C', increment the collectible
         count and replace the tile with '0'.

Exiting the Game:

    If the player moves onto the 'E' tile after collecting all items, display a 
        victory message and exit.

Tips:

    Update the Map Array: Reflect changes like collected items.
    Move Counting: Keep track of the number of moves and display it.*/
