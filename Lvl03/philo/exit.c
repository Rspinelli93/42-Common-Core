/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:29:17 by rick              #+#    #+#             */
/*   Updated: 2025/12/01 22:57:11 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_msg(char *msg)
{
	printf("%sERR: %s", RED, RESET);
	printf("%s%s%s", MAGENTA, msg, RESET);
	exit(EXIT_FAILURE);
}

void	free_philo(t_data *data)
{
	free(data);
}

void	usage_err_msg(void)
{
	printf("%sError: Wrong number of params%s\n", RED, RESET);
	printf("Usage: %s./philo %snumber_of_philosophers ", GREEN, BLUE);
	printf("%stime_to_die %stime_to_eat ", GREEN, BLUE);
	printf("%stime_to_sleep ", GREEN);
	printf("%s[number_of_times_each_philosopher_must_eat]%s\n", BLUE, RESET);
}