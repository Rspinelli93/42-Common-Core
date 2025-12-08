/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:36:03 by rick              #+#    #+#             */
/*   Updated: 2025/12/08 16:28:33 by rick             ###   ########.fr       */
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