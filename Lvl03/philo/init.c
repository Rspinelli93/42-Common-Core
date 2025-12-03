/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:51:06 by rick              #+#    #+#             */
/*   Updated: 2025/12/03 14:46:05 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data  *init_philo(int ac, char **av)
{
    t_data *data;

    data = safe_malloc(sizeof(data));
    data->num_philo = ft_atol(av[1]);
    data->tm_die = ft_atol(av[2]) * 1000;
    data->tm_eat = ft_atol(av[3]) * 1000;
	data->tm_sleep = ft_atol(av[4]) * 1000;
    if (ac == 6)
	data->num_eat = ft_atol(av[5]);

    return (data);
}


