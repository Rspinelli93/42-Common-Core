/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:38:53 by rick              #+#    #+#             */
/*   Updated: 2025/11/26 14:23:31 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Function to handle actions depending on each keysign.
It will run different functions depending on the 
keysign parameter imput.*/
int	handle_input(int keysign, t_data *data)
{
	if (keysign == XK_Escape)
		mlx_loop_end(data->conect);
	return (0);
}

/*
Step 6: Handling Keyboard Input

Make your game interactive by responding to player input!
Key Concepts:

    Event Hooks: Use mlx_hook() to listen for key presses and releases.
    Input Handling: Update the game state based on the keys pressed.

Setting Up Key Hooks:

mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &key_press, game);
mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, &key_release, game);

Handling Key Presses:

int key_press(int keycode, t_game *game) {
    if (keycode == KEY_W) {
        // Move up
    } else if (keycode == KEY_S) {
        // Move down
    }
    // Handle other keys...
    return (0);
}

Keycodes:

    W: KEY_W
    A: KEY_A
    S: KEY_S
    D: KEY_D
    Escape: KEY_ESC

Tips:

    Define Keycodes: Use constants or macros for keycodes.
    Non-Blocking Input: Update movement flags on key press/release*/