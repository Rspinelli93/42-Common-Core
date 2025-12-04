/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:51:06 by rick              #+#    #+#             */
/*   Updated: 2025/12/04 21:17:03 by rspinell         ###   ########.fr       */
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

function init_simulation(int argc, char **argv, t_data *data)
{
    // 1. Parse Arguments
    // Fill tm_die, tm_eat, tm_sleep, etc. using atoi/atol
    if (parse_input(argv, data) == ERROR)
        return (ERROR)

    // 2. Allocate Memory for Arrays
    data->forks = malloc(sizeof(t_fork) * data->num_philo)
    data->philos = malloc(sizeof(t_philo) * data->num_philo)
    
    // 3. Initialize Global Mutexes
    // You need these to protect the print function and the death flag
    // (Add these to your t_data struct if you haven't yet)
    pthread_mutex_init(&data->print_lock, NULL)
    pthread_mutex_init(&data->dead_lock, NULL)
    pthread_mutex_init(&data->meal_lock, NULL)

    // 4. Initialize Forks
    int i = 0
    while (i < data->num_philo)
    {
        data->forks[i].ix = i;
        
        // IMPORTANT: Because your struct has 't_mutex *mtx', 
        // you must malloc the mutex before initializing it.
        data->forks[i].mtx = malloc(sizeof(pthread_mutex_t))
        pthread_mutex_init(data->forks[i].mtx, NULL)
        
        i++
    }

    // 5. Initialize Philosophers
    i = 0
    while (i < data->num_philo)
    {
        t_philo *p = &data->philos[i]

        p->id = i + 1
        p->meals_cnt = 0
        p->full = false
        p->data = data  // Useful to have access to rules inside the philo
        
        // ASSIGN FORKS (The Logic)
        // One fork matches the philo's index
        p->l_fork = &data->forks[i]
        
        // The other fork is the NEXT index (modulo handles the circle for the last philo)
        p->r_fork = &data->forks[(i + 1) % data->num_philo]
        
        i++
    }
}
