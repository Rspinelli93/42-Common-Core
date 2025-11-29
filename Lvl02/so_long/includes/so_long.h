/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:38:42 by rick              #+#    #+#             */
/*   Updated: 2025/11/29 08:32:02 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define IMG_SIZE 64
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "mlx.h"
# include "mlx_int.h"

typedef struct s_myimg
{
    void    *img_ptr;   // The Identifier (The ticket)
    char    *pixel;      // The Memory Address (The actual pixel data) <--- CRITICAL
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
	int		p1_x;
	int		p1_y;
}	t_map;

typedef struct s_data
{
	void	*conect;
	void	*win;
	t_map	*map;
	int		img_size;
	int		win_width;
	int		win_height;
	int		move_count;
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
void    move_player(t_data *data ,t_map *map, int off_x, int off_y);
//* ---------- logic.c --------

//* ---------- map.c --------
void	set_size(char *adress, t_map *map);
t_map	*set_map(char *adress);
char	**set_array(t_map *map, int fd);
void	free_map(t_map *map);
void	init_p_pos(t_map *map, char **arr);

int		map_parser(char **arr, t_map *map);
int		is_rectangular(char	**arr);
int		find_sprite(char **arr, char c);
int		is_closed(char **arr, t_map *map);

//* ---------- render.c --------

int		make_buffer(t_data *data);
void	put_buffer(t_data *data, t_myimg *buff, char **arr);
void	put_filter_sprite(t_data *data, int x_pos, int y_pos, char map_char);
void	put_img_to_buff(t_data *data, t_myimg *sprite, int x_pos, int y_pos);
void	my_pixel_put(t_myimg *buffer, int x, int y, int color);

//* ---------- sprites.c --------
int		load_sprite(void *conect, t_myimg *sprite, char *path);
int 	set_sprites(t_data *data);

//* ---------- window.c --------
int		win_init(t_data *data);
int 	game_loop(t_data *data);

#endif