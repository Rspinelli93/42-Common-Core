/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:38:42 by rick              #+#    #+#             */
/*   Updated: 2025/11/23 13:36:56 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
# include "mlx_int.h"

typedef struct	s_data
{
	void	*conect;
	void	*win;
} t_data;

//* ---------- exit.c --------
int		exit_game_i(t_data *data);
void	exit_game(t_data *data);

//* ---------- keyboard.c --------
int		handle_input(int keysign, t_data *data);

//* ---------- logic.c --------

//* ---------- map.c --------

//* ---------- render.c --------

//* ---------- sprites.c --------

//* ---------- window.c --------
int		win_init(t_data *data);

#endif