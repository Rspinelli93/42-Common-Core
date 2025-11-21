/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 20:16:41 by rick              #+#    #+#             */
/*   Updated: 2025/11/21 21:01:14 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

struct s_mlx_data;

int	main(void)
{
	void	*mlx_conect;
	void	*mlx_win;

	mlx_conect = mlx_init();
	if (!mlx_conect)
		return (1);
	mlx_win = mlx_new_window(mlx_conect, 800, 1000, "Hello");
	if (!mlx_win)
	{
		mlx_destroy_display(mlx_conect);
		free(mlx_conect);
		return (1);
	}
	mlx_loop(mlx_conect);
	mlx_destroy_window(mlx_conect, mlx_win);
	mlx_destroy_display(mlx_conect);
	free(mlx_conect);
	free(mlx_win);
	return (1);
}
