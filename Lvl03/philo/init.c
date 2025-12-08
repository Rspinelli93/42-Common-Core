/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:51:06 by rick              #+#    #+#             */
/*   Updated: 2025/12/08 16:22:05 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*init_philo(int ac, char **av)
{
	t_data	*data;

	data = safe_malloc(sizeof(t_data), NULL);
	data->num_philo = ft_atol(av[1]);
	data->tm_die = ft_atol(av[2]);
	data->tm_eat = ft_atol(av[3]);
	data->tm_sleep = ft_atol(av[4]);
	if (ac == 6)
		data->n_meals = ft_atol(av[5]);
	else
		data->n_meals = -1;
	return (data);
}
void	init_tab(t_data *data)
{
	int	i;

	pthread_mutex_init(&data->print_mtx, NULL);
	pthread_mutex_init(&data->end_mtx, NULL);
	data->end_sim = false;
	data->philos = safe_malloc(sizeof(t_philo) * data->num_philo, data);
	data->forks = safe_malloc(sizeof(t_fork) * data->num_philo, data);
	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_init(&(data->forks[i].mtx), NULL);
		i++;
	}
	i = 0;
	while (i < data->num_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].r_fork = &data->forks[(i + 1) % data->num_philo];
		data->philos[i].meals_cnt = 0;
		data->philos[i].tm_last_meal = 0;
		data->philos[i].full = false;
		i++;
	}
}
