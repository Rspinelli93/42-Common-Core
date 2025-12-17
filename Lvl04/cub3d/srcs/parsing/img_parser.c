/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:09:29 by rick              #+#    #+#             */
/*   Updated: 2025/12/17 10:15:45 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// read and get addresses, store in each t_img the address

// for each t_img check that there are xpm files
// if not return exit and free all strings

// try to open this addresses and check return
// if fd is not valid then free strings and return exit

// free all t_img->address strings from data