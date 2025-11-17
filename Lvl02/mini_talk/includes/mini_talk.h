/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:22:22 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/17 14:22:18 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H
# define _POSIX_C_SOURCE 199309L

# include "libft.h"
# include "ft_printf.h"
# include <signal.h>
# include <stdio.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdbool.h>

void	ascii_to_bits(char c, int *arr);
char	bits_to_ascii(int *arr);
void	send_bits(char *str, int pid);
void	set_wait(void);
void	handle_switch(int sig);
void	setup_signal(void);
void	set_bits(int sig, int *bits, int *ix);
void	handler(int sig, siginfo_t *info, void *context);
void	setup_sigaction(void);

#endif