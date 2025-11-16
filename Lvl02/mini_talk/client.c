/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:51:26 by rick              #+#    #+#             */
/*   Updated: 2025/11/16 19:19:27 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int	main(int ac, char **av)
{
	int			pid;
	static int	bits[8];
	char		*str;
	int			i;

	if (ac != 3)
		return (0);
	pid = ft_atoi(av[1]);
	str = ft_strdup(av[2]);
	if (!str)
		return (-1);
	while (str)
	{
		i = 0;
		ascii_to_bits(*str, &bits[i]);
		while (i < 8)
		{
			if (bits[i] == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			sleep(1);
		}
		str++;
	}
	free(str);
	return (0);
}
