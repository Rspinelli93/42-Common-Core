/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:31:36 by rick              #+#    #+#             */
/*   Updated: 2025/11/29 19:27:54 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Function to initialize the window.
mlx_init() && mlx_new_window() functions run malloc
therefore the correspondent malloc check.*/
int	win_init(t_data *data)
{
	data->img_size = IMG_SIZE;
	data->win_width = data->img_size * ft_strlen(data->map->arr[0]) - IMG_SIZE;
	data->win_height = data->img_size * data->map->size - IMG_SIZE;
	data->conect = mlx_init();
	if (!data->conect)
		return (0);
	data->win = mlx_new_window(data->conect, data->win_width,
			data->win_height, "so_long");
	if (!data->win)
	{
		mlx_destroy_display(data->conect);
		free(data->conect);
		return (0);
	}
	return (1);
}

/*
Function to put inside mlx_loop_hook. It re-renders the map.*/
int	game_loop(t_data *data)
{
	put_buffer(data, &data->buffer, data->map->arr);
	return (0);
}
