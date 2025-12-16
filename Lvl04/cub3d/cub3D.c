/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:12:50 by rick              #+#    #+#             */
/*   Updated: 2025/12/16 14:40:03 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	(void)av;
	if (ac != 2)
		return (printf("Error\nUSE: ./cub3d [map-adress]\n"), 1);
/* 	if (!cub_format(av[1]))
		return (ft_printf("Error\nWrong file type. USE: '.cub'\n"), 1); */
	ft_bzero(&data, sizeof(t_data));
/* 	data.map = set_map(av[1]);
	if (!data.map)
		return (1); */
	if (!win_init(&data))
		return (printf("Error\nWin init fail"), 1); //, free_map(data.map),
	mlx_key_hook(data.win, handle_input, &data);
	mlx_hook(data.win, 17, 04, exit_game_i, &data);
	if (!set_sprites(&data))
		return (exit_game(&data), 1);
	if (!make_buffer(&data))
		return (exit_game(&data), 1);
//	game_loop(&data);
	mlx_loop(data.conect);
	exit_game(&data);
	return (0);
}
