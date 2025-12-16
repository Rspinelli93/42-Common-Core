/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:52:58 by rick              #+#    #+#             */
/*   Updated: 2025/12/16 13:53:44 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Function to handle actions depending on each keysign.
It will run different functions depending on the 
keysign parameter imput.*/
int	handle_input(int keysign, t_data *data)
{
	if (keysign == KEY_ESC)
		mlx_loop_end(data->conect);
	return (0);
}
