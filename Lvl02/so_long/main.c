/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 20:16:41 by rick              #+#    #+#             */
/*   Updated: 2025/11/23 23:15:34 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//* TODO: check if define buffer is legal



int	main(void)
{
	t_data	data;

	ft_printf("%i", get_size("maps/blocked_coin.ber"));
	if (!win_init(&data))
		return (1);
	mlx_key_hook(data.win, handle_input, &data);
	mlx_hook(data.win, 17, 04, exit_game_i, &data);
	mlx_loop(data.conect);
	exit_game(&data);

	return (0);
}

/* 
Key Features of so_long:

*    Map Parsing: Read and validate a map file.
*    Graphics Rendering: Display images and sprites.
*    Event Handling: Respond to user input via keyboard.
*    Game Logic: Implement movement, collision detection, and scoring.
*/
 