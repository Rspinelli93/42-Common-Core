/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:25:47 by rick              #+#    #+#             */
/*   Updated: 2025/12/17 10:33:27 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
bool function to check the right format of file. (.ber)*/
bool	cub_format(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 4)
		return (false);
	if (ft_strncmp(path + len - 4, ".cub", 4) == 0)
		return (true);
	return (false);
}

/*
bool function, to check if the .cub file exists.*/
bool    check_path(char *path)
{
	int		fd;

	fd = open(path, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		return (true);
	}
	return (false);
}