/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:38:53 by rick              #+#    #+#             */
/*   Updated: 2025/11/29 08:38:42 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	no_c(char **arr);

/*
Function to handle actions depending on each keysign.
It will run different functions depending on the 
keysign parameter imput.*/
int	handle_input(int keysign, t_data *data)
{
	if (keysign == KEY_ESC)
		mlx_loop_end(data->conect);
	if (keysign == KEY_W || keysign == KEY_UP)
		move_player(data, data->map, 0, -1);
	if (keysign == KEY_S || keysign == KEY_DOWN)
		move_player(data, data->map, 0, 1);
	if (keysign == KEY_A || keysign == KEY_LEFT)
		move_player(data, data->map, -1, 0);
	if (keysign == KEY_D || keysign == KEY_RIGHT)
		move_player(data, data->map, 1, 0);
	game_loop(data);
	return (0);
}

void    move_player(t_data *data ,t_map *map, int off_x, int off_y)
{
    int x;
    int y;

    x = map->p1_x;
    y = map->p1_y;
    if (map->arr[y + off_y][x + off_x] == '1')
        return ;
    else if (map->arr[y + off_y][x + off_x] == '0' || map->arr[y + off_y][x + off_x] == 'C')
    {
        map->arr[y + off_y][x + off_x] = 'P';
        map->arr[y][x] = '0';
        map->p1_x = x + off_x;
        map->p1_y = y + off_y;
        data->move_count++;
        ft_printf("Move count: %d\n", data->move_count);
    }
    else
    {
        if (no_c(map->arr) && map->arr[y + off_y][x + off_x] == 'E')
        {
            data->move_count++;
            ft_printf("Move count: %d\n", data->move_count);
            mlx_loop_end(data->conect);
        }
        else
            return ;
    }
}

static int	no_c(char **arr)
{
	int	x;
	int	y;

	y = 0;
	while (arr[y])
	{
		x = 0;
		while (arr[y][x] && arr[y][x] != '\n')
		{
			if (arr[y][x] == 'C')
			{
				return (0);
			}
			x++;
		}
		y++;
	}
    return (1);
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