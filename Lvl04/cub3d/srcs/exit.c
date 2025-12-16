/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:50:19 by rick              #+#    #+#             */
/*   Updated: 2025/12/16 13:53:59 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Function for exiting wile freeing all allocation
Same as exit_game_i, but returns void to be able to
run it with mlx_key_hook().

*int		mlx_key_hook(void *win_ptr, int (*f)(), void *param);*/
void	exit_game(t_data *data)
{
	free_images(data);
/* 	if (data->map)
		free_map(data->map); */
	if (data->win)
		mlx_destroy_window(data->conect, data->win);
	if (data->conect)
	{
		mlx_destroy_display(data->conect);
		free(data->conect);
	}
}

/*
Function to use inside hook for pressing the X, will stop
the mlx_loop(data.conect) in main.

*void mlx_hook(mlx_win_list_t *win_ptr, int x_event,
*				int x_mask, int (*f)(), void *param)*/
int	exit_game_i(t_data *data)
{
	mlx_loop_end(data->conect);
	return (0);
}

/*
Function to check if images were allocated and will free
them accrdingly running the funcrion mlx_destroy_image

*int mlx_destroy_image ( void *mlx_ptr, void *img_ptr );*/
void	free_images(t_data *data)
{
	if (data->wall_ea.img_ptr)
		mlx_destroy_image(data->conect, data->wall_ea.img_ptr);
	if (data->wall_no.img_ptr)
		mlx_destroy_image(data->conect, data->wall_no.img_ptr);
	if (data->wall_so.img_ptr)
		mlx_destroy_image(data->conect, data->wall_so.img_ptr);
	if (data->wall_we.img_ptr)
		mlx_destroy_image(data->conect, data->wall_we.img_ptr);
}
