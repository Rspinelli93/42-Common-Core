/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:38:42 by rick              #+#    #+#             */
/*   Updated: 2025/11/26 14:15:50 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define IMG_SIZE 64

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "mlx.h"
# include "mlx_int.h"

typedef struct s_myimg
{
    void    *img_ptr;   // The Identifier (The ticket)
    char    *addr;      // The Memory Address (The actual pixel data) <--- CRITICAL
    int     bpp;        // Bits per pixel (How big is one pixel?)
    int     line_len;   // Line length (How wide is one row in RAM?)
    int     endian;     // Byte order
    int     width;      // 64 (You know this)
    int     height;     // 64 (You know this)
}   t_myimg;

typedef struct s_map
{
	int		len;
	int		size;
	int		end;
	char	**arr;
}	t_map;

typedef struct s_data
{
	void	*conect;
	void	*win;
	t_map	*map;
	int		img_size;
	int		win_width;
	int		win_heigth;
	t_myimg	wall;
	t_myimg	space;
	t_myimg	water;
	t_myimg	fire;
	t_myimg	exit;
	t_myimg buffer;
}	t_data;

//* ---------- exit.c --------
int		exit_game_i(t_data *data);
void	exit_game(t_data *data);
void	free_images(t_data *data);

//* ---------- keyboard.c --------
int		handle_input(int keysign, t_data *data);

//* ---------- logic.c --------

//* ---------- map.c --------
void	set_size(char *adress, t_map *map);
t_map	*set_map(char *adress);
char	**set_array(t_map *map, int fd);
void	free_map(t_map *map);
int		map_parser(char **arr, t_map *map);
int		is_rectangular(char	**arr);
int		find_sprite(char **arr, char c);
int		is_closed(char **arr, t_map *map);

//* ---------- render.c --------
void	render_map(t_data *data, char **arr);
int		set_images(t_data *data);

//* ---------- sprites.c --------

//* ---------- window.c --------
int		win_init(t_data *data);

#endif