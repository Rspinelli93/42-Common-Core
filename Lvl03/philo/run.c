/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:54:03 by rick              #+#    #+#             */
/*   Updated: 2025/12/04 21:17:05 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

function philo_routine(t_philo *philo)
{
    // Optional: Offset start time for even/odd to prevent instant deadlock
    if (philo->id is even)
        usleep(small_amount)

    while (true)
    {
        // 0. Check if dead before starting a new cycle
        lock(data_mutex)
        if (philo->data->end_sim == true)
        {
            unlock(data_mutex)
            break ; // Exit thread
        }
        unlock(data_mutex)

        // 1. Take Forks
        // Lock left, then right (or specific order)
        pthread_mutex_lock(philo->l_fork->mtx)
        print_action(philo, "has taken a fork")
        pthread_mutex_lock(philo->r_fork->mtx)
        print_action(philo, "has taken a fork")

        // 2. Eat
        lock(meal_mutex)
        philo->tm_last_meal = current_time() // CRITICAL: Update this exactly when eating starts
        philo->meals_cnt++
        unlock(meal_mutex)

        print_action(philo, "is eating")
        precise_usleep(data->tm_eat) // Wait for eat time
        
        // 3. Drop Forks
        pthread_mutex_unlock(philo->l_fork->mtx)
        pthread_mutex_unlock(philo->r_fork->mtx)

        // 4. Check if full (if n_meals is set)
        if (data->n_meals > 0 && philo->meals_cnt >= data->n_meals)
        {
            lock(meal_mutex)
            philo->full = true
            unlock(meal_mutex)
        }

        // 5. Sleep
        print_action(philo, "is sleeping")
        precise_usleep(data->tm_sleep)

        // 6. Think
        print_action(philo, "is thinking")
        // (Loop repeats)
    }
}

function monitor_routine(t_data *data)
{
    while (true)
    {
        bool all_full = true; // Assume yes, disprove inside loop

        for (each philo in data->philos)
        {
            // 1. Check Death
            lock(meal_mutex)
            long time_since_meal = current_time() - philo->tm_last_meal
            bool is_full = philo->full
            unlock(meal_mutex)

            if (time_since_meal > data->tm_die && is_full == false)
            {
                // PHILO DIED
                lock(data_mutex)
                data->end_sim = true
                unlock(data_mutex)
                
                // Print explicitly here because other threads stop printing when end_sim is true
                print("Philo X died") 
                return ; // Stop monitoring, simulation ends
            }

            // 2. Check if this specific philo is NOT full yet
            if (is_full == false)
                all_full = false
        }

        // 3. Check if EVERYONE is full (only if n_meals option is on)
        if (data->n_meals > 0 && all_full == true)
        {
            lock(data_mutex)
            data->end_sim = true
            unlock(data_mutex)
            return ; // Everyone ate enough, stop
        }
        
        usleep(500) // Small delay to relieve CPU
    }
}