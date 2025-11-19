/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:51:26 by rick              #+#    #+#             */
/*   Updated: 2025/11/19 11:43:33 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

// todo: Check exit funct, change sleep for usleep
// todo: check global variables!

//* A regular bool var can be changed by the signal handler
//* while the main code is checking it. This why needs to be marked as volatile
volatile sig_atomic_t	g_ready = true;

int	main(int ac, char **av)
{
	char	*str;
	int		pid;
	int		len;

	if (ac != 3)
		return (0);
	pid = ft_atoi(av[1]);
	str = av[2];
	len = ft_strlen(str);
	setup_signal();
	while (len)
	{
		send_bits(str, pid);
		str++;
		len--;
	}
	send_bits(str, pid);
	return (EXIT_SUCCESS);
}

/*
* Here we set sa_handler instead of sa_sigaction, since we dont
* need to set any flags (like in server side that we need the
* flag to get the PID of the client).*/
void	setup_signal(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_handler = handle_switch;
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) < 0)
		exit(EXIT_FAILURE);
}

/*
* Sending bit by bit, while setting to false g_ready and then
* waiting until getting the signal back.
! Change sleep for usleep*/
void	send_bits(char *str, int pid)
{
	int			i;
	static int	bits[8];

	i = 0;
	ascii_to_bits(*str, bits);
	while (i < 8)
	{
		set_wait();
		if (bits[i] == 0)
		{
			if (kill(pid, SIGUSR1) < 0)
				exit(EXIT_FAILURE);
		}
		else
		{
			if (kill(pid, SIGUSR2) < 0)
				exit(EXIT_FAILURE);
		}
		i++;
		sleep(1);
		while (!g_ready)
			pause();
	}
}

/*
* Handler funct, sets g_ready to true when
* recieving the signal from server*/
void	handle_switch(int sig)
{
	if (sig == SIGUSR1)
		g_ready = true;
}

/*
* Set g_ready to false.*/
void	set_wait(void)
{
	g_ready = false;
}
