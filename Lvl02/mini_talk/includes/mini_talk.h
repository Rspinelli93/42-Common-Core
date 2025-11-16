/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:22:22 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/16 18:16:40 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINI_TALK_H
#define MINI_TALK_H
#define _POSIX_C_SOURCE 199309L

#include "libft.h"
#include "ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>

void    ascii_to_bits(char c, int *arr);
char    bits_to_ascii(int *arr);

#endif