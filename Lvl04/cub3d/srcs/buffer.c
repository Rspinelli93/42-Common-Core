/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:38:33 by rick              #+#    #+#             */
/*   Updated: 2025/12/16 14:40:41 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Function to create the buffer where is "painted" pixel by
pixel before being rendered in the window.
The canvas is created with mlx_new_image, and the data
necessary for "painting each pixel" is set with 
mlx_get_data_addr.

mlx_get_data_addr returns a pointer to the pixel (in this
case, the pixel at pos (0,0))*/
int	make_buffer(t_data *data)
{
	data->buffer.height = data->win_height;
	data->buffer.width = data->win_width;
	data->buffer.img_ptr = mlx_new_image(data->conect,
			data->win_width,
			data->win_height);
	if (!data->buffer.img_ptr)
		return (0);
	data->buffer.pixel = mlx_get_data_addr(data->buffer.img_ptr,
			&data->buffer.bpp,
			&data->buffer.line_len,
			&data->buffer.endian);
	if (!data->buffer.pixel)
		return (0);
	return (1);
}

/*
put_buffer function basically populates the buffer to then
push it to the window. This function will rerun every time
we make a change in the position of the player.*/
void	put_buffer(t_data *data, t_myimg *buff, char **arr)
{
	int	j;
	int	i;

	j = 0;
	while (arr[j])
	{
		i = 0;
		while (arr[j][i] && arr[j][i] != '\n')
		{
			put_filter_sprite(data, i * IMG_SIZE, j * IMG_SIZE, arr[j][i]);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(data->conect, data->win, buff->img_ptr, 0, 0);
}

/*
+ This function is my version of mlx_pixel_put, but to be used
+ not to put the pixel in the window but inside the buffer, that
+ we will after push in the window all at once.

* x and y are the coordenates inside the buffer.
* color is the color of the pixel of the sprite that
* I want to put inside the buffer.*/
void	my_pixel_put(t_myimg *buffer, int x, int y, int color)
{
	int	offset;

	offset = (buffer->line_len * y) + (x * (buffer->bpp / 8));
	*((unsigned int *)(offset + buffer->pixel)) = color;
}
