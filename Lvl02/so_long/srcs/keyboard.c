/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:38:53 by rick              #+#    #+#             */
/*   Updated: 2025/11/28 21:20:27 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Function to handle actions depending on each keysign.
It will run different functions depending on the 
keysign parameter imput.*/
int	handle_input(int keysign, t_data *data)
{
    data->move_count++;
    ft_printf("Move count: %d\n", data->move_count);
	if (keysign == KEY_ESC)
		mlx_loop_end(data->conect);
/*     if (keysign == 119 || keysign == 65362)
        move_player(data, 0, -1);
    if (keysign == 115 || keysign == 65364)
        move_player(data, 0, 1);
    if (keysign == 97 || keysign == 65361)
        move_player(data, -1, 0);
    if (keysign == 100 || keysign == 65363)
        move_player(data, 1, 0); */
	return (0);
}

void    move_player(t_data *data, int x, int y);

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