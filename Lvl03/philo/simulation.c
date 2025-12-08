/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:54:03 by rick              #+#    #+#             */
/*   Updated: 2025/12/08 16:31:08 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *philo)
{
    // 1. Cast arg to (t_philo *).

    // 2. Handle 1 Philosopher Edge Case:
    //    - If num_philo == 1:
    //      - Lock l_fork.
    //      - Print "has taken a fork".
    //      - ft_usleep(time_to_die).
    //      - Unlock l_fork.
    //      - Return NULL (He dies).

    // 3. Optimization (Desync):
    //    - If philo->id is even, ft_usleep(1) or similar.
    //    - This prevents all philos from grabbing forks at the exact same time.

    // 4. Infinite Loop (while simulation is active):
    {
        // --- EATING ---
        // Lock l_fork.
        // Print "has taken a fork".
        // Lock r_fork.
        // Print "has taken a fork".
        
        // Print "is eating".
        // Lock internal mutex (to protect last_meal update).
        // Update last_meal = get_time().
        // Increment meals_cnt.
        // Unlock internal mutex.
        
        // ft_usleep(time_to_eat).
        
        // Unlock r_fork.
        // Unlock l_fork.

        // --- SLEEPING ---
        // Print "is sleeping".
        // ft_usleep(time_to_sleep).

        // --- THINKING ---
        // Print "is thinking".
    }
    // Return NULL.
}

void	*monitor_routine(void *data)
{
    // 1. Cast arg to (t_data *).

    // 2. Infinite Loop (while 1):
    {
        // Iterate through all philosophers (i = 0 to num_philo):
        {
            // Lock internal mutex (to read meal data safely).
            
            // Check Death:
            // If (current_time - philo[i].last_meal > time_to_die):
            //      - Print "X died".
            //      - Set global flag end_sim = true.
            //      - Unlock internal mutex.
            //      - Return NULL (Simulation stops).
            
            // Check Full (Optional optimization):
            // If (n_meals option is set AND philo[i].meals_cnt >= n_meals):
            //      - Increment a counter for full philos.

            // Unlock internal mutex.
        }

        // Check if ALL are full:
        // If (full_philo_counter == num_philo):
        //      - Set global flag end_sim = true.
        //      - Return NULL.

        // Reset full_philo_counter to 0 for next loop.
        
        // usleep(500) -> Small delay to reduce CPU usage.
    }
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