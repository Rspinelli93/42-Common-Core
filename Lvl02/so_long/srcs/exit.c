/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:42:36 by rick              #+#    #+#             */
/*   Updated: 2025/11/23 13:33:41 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Function for exiting wile freeing all allocation
Same as exit_game_i, but returns void to be able to
run it with mlx_key_hook().
*int		mlx_key_hook(void *win_ptr, int (*f)(), void *param);*/
void	exit_game(t_data *data)
{
	mlx_destroy_window(data->conect, data->win);
	mlx_destroy_display(data->conect);
	free(data->conect);
	exit(0);
}

/*
Function for exiting wile freeing all allocation
Same as exit_game, but returns an int to be able to
run it through mlx_hook()
*void mlx_hook(mlx_win_list_t *win_ptr, int x_event,
*				int x_mask, int (*f)(), void *param)*/
int exit_game_i(t_data *data)
{
	mlx_destroy_window(data->conect, data->win);
	mlx_destroy_display(data->conect);
	free(data->conect);
	exit(0);
	return (0);
}


/*
* ------------------------------------------------------------------------------
Step 8: Cleaning Up and Exiting

Gracefully handle exiting the game and freeing up resources.
Key Concepts:

    Memory Management: Free allocated memory to prevent leaks.
    Exit Hooks: Handle window close events.

Function to Exit the Game:

int exit_game(t_game *game) {
    // Free images
    // Destroy window
    // Free map array
    exit(0);
}

Setting Up the Exit Hook:

mlx_hook(game->win_ptr, DestroyNotify, NoEventMask, &exit_game, game);

Tips:

    Free in Reverse Order: Free resources in the opposite order of allocation.
    Handle All Exit Cases: Include Escape key and window close button. */

