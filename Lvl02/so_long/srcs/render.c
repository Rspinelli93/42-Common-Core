/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:37:55 by rick              #+#    #+#             */
/*   Updated: 2025/11/26 14:15:10 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Render map will take the images previously stored in data and will
put them to window.*/
void	render_map(t_data *data, char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j] && arr[i][j] != '\n')
		{
			if (arr[i][j] == '1')
				mlx_put_image_to_window(data->conect, data->win, data->wall.img_ptr, j * 64, i * 64);
			else if (arr[i][j] == '0')
				mlx_put_image_to_window(data->conect, data->win, data->space.img_ptr, j * 64, i * 64);
			else if (arr[i][j] == 'P')
				mlx_put_image_to_window(data->conect, data->win, data->water.img_ptr, j * 64, i * 64);
			else if (arr[i][j] == 'E')
				mlx_put_image_to_window(data->conect, data->win, data->exit.img_ptr, j * 64, i * 64);
			else if (arr[i][j] == 'C')
				mlx_put_image_to_window(data->conect, data->win, data->fire.img_ptr, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

/*
This function runs the function mlx_xpm_file_to_image in all the t_myimg 
within the struct t_data data.*/
int	set_images(t_data *data)
{
	data->img_size = IMG_SIZE;
	data->exit.img_ptr = mlx_xpm_file_to_image(data->conect,
			"./imgs/exit.xpm", &(data->img_size), &(data->img_size));
	data->fire.img_ptr = mlx_xpm_file_to_image(data->conect,
			"./imgs/fire.xpm", &(data->img_size), &(data->img_size));
	data->space.img_ptr = mlx_xpm_file_to_image(data->conect,
			"./imgs/space.xpm", &(data->img_size), &(data->img_size));
	data->wall.img_ptr = mlx_xpm_file_to_image(data->conect,
			"./imgs/wall.xpm", &(data->img_size), &(data->img_size));
	data->water.img_ptr = mlx_xpm_file_to_image(data->conect,
			"./imgs/water.xpm", &(data->img_size), &(data->img_size));
	if (!data->wall.img_ptr || !data->exit.img_ptr || !data->fire.img_ptr
		|| !data->space.img_ptr || !data->water.img_ptr)
		return (ft_printf("Error\nProblem loading images (check paths!)\n"), 0);
	return (1);
}

void	refresh_map(void)
{
	// create a new struct to render
	//		containing map copy to be able to modify
	// a new image buffer where we are going to paste all the little images
	// height and width of window?
}
/* 
** Put an image to the given window.
**
** @param	void *mlx_ptr	the mlx instance;
** @param	void *win_ptr	the window instance;
** @param	int  x			the x location of where the image ought to be placed;
** @param	int  y			the y location of where the image ought to be placed;
** @return	int				has no return value (bc).
-void       *mlx_xpm_file_to_image ( void *mlx_ptr, char *filename, 
-						int *width, int *height );
-int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, 
-						void *img_ptr, int x, int y);
-----------------------------------------
Step 5: Rendering the Game World

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
