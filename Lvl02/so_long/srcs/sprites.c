/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:33:03 by rick              #+#    #+#             */
/*   Updated: 2025/11/28 20:50:26 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
* load_image is use to load one specific image.
* 1. Loads XPM to get the void pointer and dimensions.
* 2. Set the memory address to copy pixels from afterwards.
* 3. Sets width and height to IMG_SIZE
* Returns 0 if loading failed, 1 if success.

used function:
char	*mlx_get_data_addr(t_img *img,int *bits_per_pixel,
			   int *size_line,int *endian)

  *bits_per_pixel = img->bpp;
  *size_line = img->size_line;
  *endian = img->image->byte_order;
  return (img->data);
*/
int load_sprite(void *conect, t_myimg *sprite, char *path)
{
	sprite->img_ptr = mlx_xpm_file_to_image(conect, path, &sprite->width, &sprite->height);
	if (!sprite->img_ptr)
		return (0);
	sprite->pixel = mlx_get_data_addr(sprite->img_ptr, &sprite->bpp, 
									&sprite->line_len, &sprite->endian);
	if (!sprite->pixel)
		return (0);
	sprite->height = IMG_SIZE;
	sprite->width = IMG_SIZE;
	return (1);
}

/*
* set_images runs the function load_sprite for every image:
* (wall, space, water, exit, fire).
* Setting their respectives t_myimg inside the game t_data
* Returns 0 if loading failed, 1 if success.*/
int set_sprites(t_data *data)
{
	if (!load_sprite(data->conect, &data->wall, "./imgs/wall.xpm"))
		return (ft_printf("Failed to load: Wall\n"), 0);
	if (!load_sprite(data->conect, &data->space, "./imgs/space.xpm"))
		return (ft_printf("Failed to load: Space\n"), 0);
	if (!load_sprite(data->conect, &data->water, "./imgs/water.xpm"))
		return (ft_printf("Failed to load: Water\n"), 0);
	if (!load_sprite(data->conect, &data->exit, "./imgs/exit.xpm"))
		return (ft_printf("Failed to load: Exit\n"), 0);
	if (!load_sprite(data->conect, &data->fire, "./imgs/fire.xpm"))
		return (ft_printf("Failed to load: Fire\n"), 0);
	return (1);
}
