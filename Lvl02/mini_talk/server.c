/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:50:52 by rick              #+#    #+#             */
/*   Updated: 2025/11/17 14:27:32 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

//todo: sigaddset return -1 in error, see later
//todo: check on header, if the define _POSIX_C_SOURCE is possible to use

/*
* Set the actions for the signals
* Print the PID.
* Wait PASSIVELY for signals.*/
int	main(void)
{
	setup_sigaction();
	ft_printf("PID: %i\n", getpid());
	while (1)
		pause();
	return (EXIT_SUCCESS);
}

/*
* Sets 0 or 1 depending on sig.
* Updates ix value.*/
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

/*
* We set each position of the static array of int accordingly
*	with the signals recieved.
* We set all positions to 0 after finishing each char
* We send after each char a signal to the client.*/
void	handler(int sig, siginfo_t *info, void *context)
{
	static int	bits[8];
	static int	ix;
	char		c;

	(void)context;
	set_bits(sig, bits, &ix);
	if (ix == 8)
	{
		c = bits_to_ascii(bits);
		write(1, &c, 1);
		if (c == '\0')
			write(1, "\n", 1);
		ix = 0;
		ft_memset(bits, 0, sizeof(bits));
	}
	if (kill(info->si_pid, SIGUSR1) < 0)
		exit(EXIT_FAILURE);
}

/*
* Here we set sa_sigaction to be the handler funct
* add masks for security, so we block signals during
* handler execution.
* flags = is going to give us the PID of the sender
* in this case the client.c*/
void	setup_sigaction(void)
{
	sigset_t			set;
	struct sigaction	sa;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_mask = set;
	if (sigaction(SIGUSR1, &sa, NULL) < 0
		|| sigaction(SIGUSR2, &sa, NULL) < 0)
		exit(EXIT_FAILURE);
}
