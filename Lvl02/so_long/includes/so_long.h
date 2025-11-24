/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:38:42 by rick              #+#    #+#             */
/*   Updated: 2025/11/24 15:43:57 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "mlx.h"
# include "mlx_int.h"

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
}	t_data;

//* ---------- exit.c --------
int		exit_game_i(t_data *data);
void	exit_game(t_data *data);

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

//* ---------- sprites.c --------

//* ---------- window.c --------
int		win_init(t_data *data);

#endif