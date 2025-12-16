/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:11:27 by rick              #+#    #+#             */
/*   Updated: 2025/12/16 13:49:49 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Function to initialize the window.
mlx_init() && mlx_new_window() functions run malloc
therefore the correspondent malloc check.*/
int	win_init(t_data *data)
{
	data->img_size = IMG_SIZE;
	data->win_width = WIN_WIDTH;
	data->win_height = WIN_HEIGHT;
	data->conect = mlx_init();
	if (!data->conect)
		return (0);
	data->win = mlx_new_window(data->conect, data->win_width,
			data->win_height, "cub3d");
	if (!data->win)
	{
		mlx_destroy_display(data->conect);
		free(data->conect);
		return (0);
	}
	return (1);
}
