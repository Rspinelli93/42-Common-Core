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
* load_image is use to load one specific image.
* 1. Loads XPM to get the void pointer and dimensions.
* 2. Set the memory address to copy pixels from afterwards.
* Returns 0 if loading failed, 1 if success.
*/
int load_image(void *mlx, t_myimg *img, char *path)
{
	img->img_ptr = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	if (!img->img_ptr)
		return (0);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, 
									&img->line_len, &img->endian);
	return (1);
}

/*
* set_images runs the function load_image for every image:
* (wall, space, water, exit, fire).
* Setting their respectives t_myimg inside the game t_data
* Returns 0 if loading failed, 1 if success.*/
int set_images(t_data *data)
{
	if (!load_image(data->conect, &data->wall, "./imgs/wall.xpm"))
		return (ft_printf("Failed to load: Wall\n"), 0);
	if (!load_image(data->conect, &data->space, "./imgs/space.xpm"))
		return (ft_printf("Failed to load: Space\n"), 0);
	if (!load_image(data->conect, &data->water, "./imgs/water.xpm"))
		return (ft_printf("Failed to load: Water\n"), 0);
	if (!load_image(data->conect, &data->exit, "./imgs/exit.xpm"))
		return (ft_printf("Failed to load: Exit\n"), 0);
	if (!load_image(data->conect, &data->fire, "./imgs/fire.xpm"))
		return (ft_printf("Failed to load: Fire\n"), 0);
	return (1);
}

//! DOUBLE MALLOC
/*
Function to create the buffer where is "painted" pixel by
pixel before being rendered in the window.
The canvas is created with mlx_new_image, and the data
necessary for "painting each pixel" is set with 
mlx_get_data_addr.*/
int	make_buffer(t_data *data)
{
	data->buffer.height = data->win_height;
	data->buffer.width = data->win_width;
	data->buffer.img_ptr = mlx_new_image(data->conect,
		data->win_width,
		data->win_height);
	if (!data->buffer.img_ptr)
		return (0);
	data->buffer.addr = mlx_get_data_addr(data->buffer.img_ptr,
		&data->buffer.bpp,
		&data->buffer.line_len,
		&data->buffer.endian);
	if (!data->buffer.addr)
		return (0);
	return (1);
}

/*
Data: (The Destination) The main struct (which holds the buffer).
Sprite: (The Source) The specific sprite you want to draw (e.g., &data->wall).
The X Offset: Where on the screen (horizontal) to place the left edge of the image.
The Y Offset: Where on the screen (vertical) to place the top edge of the image.


Here is the mental model for the loop. We are going to iterate 
through every single pixel of the Sprite (the small image) and
copy it to the correct location in the Buffer (the big image).*/
void	put_img_to_buff(t_data *data, t_myimg *sprite, int x_pos, int y_pos)
{
	int	i;
	int	j;
	int	offset;

	i = 0;
	j = 0;
	offset = 0;
	while (i < sprite->height)
	{
		j = 0
		while (j < sprite->width)
		{
            // STEP 1: FIND THE PIXEL IN THE SPRITE (SOURCE)
            // Calculate memory offset using sprite->line_len
            src_offset = (y * sprite->line_len) + (x * (sprite->bpp / 8))
            
            // Get the memory address of this specific pixel
            pixel_ptr = sprite->addr + src_offset
            
            color = *(unsigned int *)pixel_ptr

            // STEP 2: CHECK TRANSPARENCY
            // (In XPM, transparent pixels often have a specific color, 
            // e.g., 0xFF000000 (black) or a "magic pink". 
            // If the color is NOT transparent, we copy it.)
            
            if (color != TRANSPARENT_COLOR)
            {
				my_pixel_put()
			}
			j++
    	}
		i++
	}
}

/*
This is the heart of your rendering engine. You are creating a function that acts like a "stamp."

The Prototype

You need 4 pieces of information to do this job:

    The Destination: The main struct (which holds the buffer).

    The Source: The specific sprite you want to draw (e.g., &data->wall).

    The X Offset: Where on the screen (horizontal) to place the left edge of the image.

    The Y Offset: Where on the screen (vertical) to place the top edge of the image.

C

void put_img_to_img(t_data *data, t_myimg *sprite, int x_pos, int y_pos);

The Logic (Pseudocode)

Here is the mental model for the loop. We are going to iterate through every single pixel of the Sprite (the small image) and copy it to the correct location in the Buffer (the big image).
Plaintext

FUNCTION put_img_to_img(data, sprite, x_pos, y_pos)
{
    // Iterators for the sprite's grid
    y = 0
    x = 0

    // Loop through every row of the sprite
    WHILE (y < sprite->height)
    {
        x = 0
        // Loop through every pixel in that row
        WHILE (x < sprite->width)
        {
            // STEP 1: FIND THE PIXEL IN THE SPRITE (SOURCE)
            // Calculate memory offset using sprite->line_len
            src_offset = (y * sprite->line_len) + (x * (sprite->bpp / 8))
            
            // Get the memory address of this specific pixel
            pixel_ptr = sprite->addr + src_offset
            
            // Read the color (cast to unsigned int to get the full RGBA value)
            color = *(unsigned int *)pixel_ptr

            // STEP 2: CHECK TRANSPARENCY
            // (In XPM, transparent pixels often have a specific color, 
            // e.g., 0xFF000000 (black) or a "magic pink". 
            // If the color is NOT transparent, we copy it.)
            
            IF (color != TRANSPARENT_COLOR)
            {
                // STEP 3: FIND THE PIXEL IN THE BUFFER (DESTINATION)
                // Calculate the matching position on the big canvas
                // Note: We add x_pos and y_pos here!
                dest_y = y_pos + y
                dest_x = x_pos + x
                
                dest_offset = (dest_y * data->buffer.line_len) + (dest_x * (data->buffer.bpp / 8))
                
                // Get the address in the buffer
                dest_ptr = data->buffer.addr + dest_offset
                
                // Write the color into the buffer
                *(unsigned int *)dest_ptr = color
            }

            x++
        }
        y++
    }
}

Key Details for Implementation

    Pointer Arithmetic: Your addr is a char *. When you add the offset, you are 
	moving byte-by-byte. This is correct. However, when you read or write
	 the color, you must cast that address to (unsigned int *).

        Why? Because a pixel is 4 bytes (Red, Green, Blue, Alpha). If you 
		treat it as a char, you only copy the Blue part (usually).

    Transparency: This is the hardest part of manual copying. Since you
	 are not using MLX's internal functions, you have to decide what
	  "Transparent" means.

        Simple way: Open your .xpm file in a text editor. Look at the 
		top. It will say something like " c None". That means spaces are 
		transparent.

        In Code: In MiniLibX, "None" (Transparency) usually translates to 
		the color integer 0xFF000000 (Pure Black with full transparency) or
		sometimes just 0x0. You might need to experiment to see which color 
		code your sprites use for "invisible."
*/
void	my_pixel_put()
{
	// STEP 3: FIND THE PIXEL IN THE BUFFER (DESTINATION)
	// Calculate the matching position on the big canvas
	// Note: We add x_pos and y_pos here!
	dest_y = y_pos + y
	dest_x = x_pos + x
	
	dest_offset = (dest_y * data->buffer.line_len) + (dest_x * (data->buffer.bpp / 8))
	
	// Get the address in the buffer
	dest_ptr = data->buffer.addr + dest_offset
	
	// Write the color into the buffer
	*(unsigned int *)dest_ptr = color
}
