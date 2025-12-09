/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:36:03 by rick              #+#    #+#             */
/*   Updated: 2025/12/09 10:10:55 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_data *data)
{
	if (!data)
		return ;
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
	free(data);
}

void	*safe_malloc(size_t bytes, t_data *data)
{
	void	*ret;

	ret = malloc(bytes);
	if (!ret)
	{
		free_philo(data);
		exit_msg("Malloc Error");
	}
	return (ret);
}

/* Prints message according to the type:
* 1 = has taken a fork
* 2 = is eating
* 3 = is sleeping
* 4 = is thinking
* 5 = died */
void	print_msg(t_philo *philo, int philo_id, int type)
{
	long	time;

	pthread_mutex_lock(&philo->data->print_mtx);
	time = get_time() - philo->data->start_time;

	pthread_mutex_lock(&philo->data->end_mtx);
	if (!philo->data->end_sim || type == 5)
	{
		if (type == 1)
			printf("%ld %d has taken a fork\n", time, philo_id);
		else if (type == 2)
			printf("%ld %d is eating\n", time, philo_id);
		else if (type == 3)
			printf("%ld %d is sleeping\n", time, philo_id);
		else if (type == 4)
			printf("%ld %d is thinking\n", time, philo_id);
		else if (type == 5)
			printf("%ld %d died\n", time, philo_id);
	}
	pthread_mutex_unlock(&philo->data->end_mtx);
	pthread_mutex_unlock(&philo->data->print_mtx);
}

/* Returns current time in milliseconds */
long    get_time(void)
{
    struct timeval  tv;

    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

/* Custom sleep: more precise than usleep and checks for death while waiting */
void    ft_usleep(long time_in_ms, t_data *data)
{
    long    start_time;

    start_time = get_time();
    while ((get_time() - start_time) < time_in_ms)
    {
        // Optional: Check for death here to stop sleeping immediately if sim ends
        // if (check_sim_ended(data))
        //    break;
        usleep(500); // Check every 0.5ms
    }
}