/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:38:53 by rick              #+#    #+#             */
/*   Updated: 2025/11/29 20:14:48 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	no_c(char **arr, char c);
static void	mv_player_helper(t_data *data, t_map *map, int off_x, int off_y);

/*
Function to handle actions depending on each keysign.
It will run different functions depending on the 
keysign parameter imput.*/
int	handle_input(int keysign, t_data *data)
{
	if (keysign == KEY_ESC)
		mlx_loop_end(data->conect);
	if (keysign == KEY_W || keysign == KEY_UP)
		move_player(data, data->map, 0, -1);
	if (keysign == KEY_S || keysign == KEY_DOWN)
		move_player(data, data->map, 0, 1);
	if (keysign == KEY_A || keysign == KEY_LEFT)
		move_player(data, data->map, -1, 0);
	if (keysign == KEY_D || keysign == KEY_RIGHT)
		move_player(data, data->map, 1, 0);
	game_loop(data);
	return (0);
}

/*
Function to change positions in each move, the function will 
modify the map accordingly.*/
void	move_player(t_data *data, t_map *map, int off_x, int off_y)
{
	int	x;
	int	y;

	x = map->p1_x;
	y = map->p1_y;
	if (map->arr[y + off_y][x + off_x] == '0'
			|| map->arr[y + off_y][x + off_x] == 'C')
		mv_player_helper(data, map, off_x, off_y);
	else if (map->arr[y + off_y][x + off_x] == 'E')
	{
		if (no_c(map->arr, 'C'))
		{
			data->move_count++;
			ft_printf("Move count: %d\n", data->move_count);
			mlx_loop_end(data->conect);
		}
		else
			mv_player_helper(data, map, off_x, off_y);
	}
	else
		return ;
}

/*
Function to change positions in each move, the function will 
modify the map accordingly.
Used for 'C' or '0' cases or when exit but still 'C' in map.*/
static void	mv_player_helper(t_data *data, t_map *map, int off_x, int off_y)
{
	int	x;
	int	y;

	x = map->p1_x;
	y = map->p1_y;
	if (x == map->e_x && y == map->e_y)
		map->arr[y][x] = 'E';
	else
		map->arr[y][x] = '0';
	map->arr[y + off_y][x + off_x] = 'P';
	map->p1_x = x + off_x;
	map->p1_y = y + off_y;
	data->move_count++;
	ft_printf("Move count: %d\n", data->move_count);
}

/*
boolean function that returns true if no C char where found
in the array.*/
static int	no_c(char **arr, char c)
{
	int	x;
	int	y;

	y = 0;
	while (arr[y])
	{
		x = 0;
		while (arr[y][x] && arr[y][x] != '\n')
		{
			if (arr[y][x] == c)
			{
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
