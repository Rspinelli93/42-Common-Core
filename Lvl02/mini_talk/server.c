/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:50:52 by rick              #+#    #+#             */
/*   Updated: 2025/11/16 19:14:10 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	set_bits(int sig, int *bits, int *ix);
void	handler(int sig, siginfo_t *info, void *context);
void	setup_sigaction(void);

int	main(void)
{
	pid_t		pid;

	setup_sigaction();
	pid = getpid();
	ft_printf("PID: %i", pid);

	while (1)
    	pause();

	return (0);
}

// sigaddset return -1 in error, see later
// check on header, if the define _POSIX_C_SOURCE is possible to use

void	set_bits(int sig, int *bits, int *ix)
{
	if (sig == SIGUSR1)
		bits[*ix] = 0;
	else if (sig == SIGUSR2)
		bits[*ix] = 1;
	else
		return ;
	(*ix)++;
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static int	bits[8];
	static int	ix;
	char		c;

	(void)info; //info->si_pid the PID of the client that sent the signal
	(void)context;

	set_bits(sig, bits, &ix);

	if (ix == 8)
	{
		c = bits_to_ascii(bits);
		write(1, &c, 1);
		ix = 0;
	}
}

void	setup_sigaction(void)
{
	sigset_t	set;
	struct sigaction sa1;
	struct sigaction sa2;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);

	sa1.sa_sigaction = handler;
	sa1.sa_flags = SA_SIGINFO;
	sa1.sa_mask = set;

	sa2.sa_sigaction = handler;
	sa2.sa_flags = SA_SIGINFO;
	sa2.sa_mask = set;

	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa2, NULL);
}