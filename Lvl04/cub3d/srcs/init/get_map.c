/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:06:44 by rick              #+#    #+#             */
/*   Updated: 2025/12/17 10:31:30 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_map(t_data *data)
{
    
}

/*
Function to free a double array of strings, used for raw_map and map*/
void	free_2d_arr(char **map)
{
    int i;

	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
}
