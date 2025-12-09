/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:54:03 by rick              #+#    #+#             */
/*   Updated: 2025/12/09 10:50:29 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	one_philo(t_philo *philo);
static void	eating(t_philo *philo);

/*
1. Handle 1 Philosopher Edge Case.
2. Prevent all philos from grabbing forks at the same time:
	- If philo->id is even, ft_usleep()
3. Infinite Loop (while simulation is active):
    -Check if dead before starting new cycle
*EAT
	- eating();
*SLEEP
	- Print "is sleeping".
	- ft_usleep(time_to_sleep).
*THINK
	- Print "is thinking".
*/
void    *philo_routine(void *philosopher)
{
    t_philo *philo;

    philo = (t_philo *)philosopher;
    if (philo->data->num_philo == 1)
        return (one_philo(philo), NULL);
    if (philo->id % 2 == 0)
        usleep(5);
    while (1)
    {
        pthread_mutex_lock(&philo->data->end_mtx);
        if (philo->data->end_sim)
        {
            pthread_mutex_unlock(&philo->data->end_mtx);
            break;
        }
        pthread_mutex_unlock(&philo->data->end_mtx);
        eating(philo);
        print_msg(philo, philo->id, 3);
        ft_usleep(philo->data->tm_sleep, philo->data);
        print_msg(philo, philo->id, 4);
    }
    return (NULL);
}

/*
1. Infinite Loop (while 1):
- Iterate through all philosophers (i = 0 to num_philo).
- Lock internal meal_mtx.
*DEATH CHECK
	- If (get_time() - last_meal > time_to_die):
		- Set end_sim = true.
		- Print "died".
		- Unlock meal_mtx & Return NULL.
*FULL CHECK (Optional)
	- If (n_meals > 0 AND meals_cnt >= n_meals):
		- Increment "full_philos" counter.
- Unlock internal meal_mtx.
*END CONDITION
	- If (full_philos == num_philo):
		- Set end_sim = true.
		- Return NULL.
- Reset full_philos counter.
- usleep(500) (Reduce CPU usage).
*/
void	*monitor_routine(void *table_data)
{
	t_data *data;
	int		i;

	data = (t_data *)table_data;
	while (1)
	{
		while (i < data->num_philo)
		{
			pthread_mutex_lock(&data->philos[i].meal_mtx);
			if (get_time() - data->philos[i].tm_last_meal > data->tm_die)
			{
				data->end_sim = true;
				print_msg(&data->philos[i], i + 1, 5);
				pthread_mutex_unlock(&data->philos[i].meal_mtx);
				return (NULL);
			}
		}
	}
} 

/*
/ Lock l_fork & Print "has taken a fork".
/ Lock r_fork & Print "has taken a fork".
/ Print "is eating".
/ Lock internal mutex (to protect last_meal update).
	* important, so there is no data race between the monitor and
	* the philo changing the data on "last meal and meal count"
/ Update last_meal = get_time().
/ Increment meals_cnt.
/ Unlock internal mutex.
/ ft_usleep(time_to_eat).
/ Unlock r_fork & Unlock l_fork. */
static void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork->mtx);
	print_msg(philo, philo->id, 1);
	pthread_mutex_lock(&philo->r_fork->mtx);
	print_msg(philo, philo->id, 1);
	print_msg(philo, philo->id, 2);
	pthread_mutex_lock(&philo->meal_mtx);
	philo->tm_last_meal = get_time();
	philo->meals_cnt++;
	pthread_mutex_unlock(&philo->meal_mtx);
	ft_usleep(philo->data->tm_eat, philo->data);
	pthread_mutex_unlock(&philo->r_fork->mtx);
	pthread_mutex_unlock(&philo->l_fork->mtx);
}

/*  
	If num_philo == 1:
	Lock l_fork.
	Print "has taken a fork".
	ft_usleep(time_to_die).
	Unlock l_fork.
	Return NULL (He dies). */
static void	one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork->mtx);
	print_msg(get_time() - philo->data->start_time, philo->id, 1);
	ft_usleep(philo->data->tm_die, philo->data);
	pthread_mutex_unlock(&philo->l_fork->mtx);
}

void	start_simulation(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_time();
	while (i < data->num_philo)
	{
		data->philos[i].tm_last_meal = data->start_time;
        pthread_create(&data->philos[i].trd, NULL, philo_routine, &data->philos[i]);
		i++;
	}
    pthread_create(&data->monitor, NULL, monitor_routine, data);
	i = 0;
	while (i < data->num_philo)
	{
        pthread_join(data->philos[i].trd, NULL);
		i++;
	}
    pthread_join(data->monitor, NULL);
}