/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:21:02 by rick              #+#    #+#             */
/*   Updated: 2025/12/03 21:10:26 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2
// https://www.youtube.com/watch?v=oq29KUy29iQ&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=4


// av[] number_of_philosophers | time_to_die | time_to_eat | time_to_sleep | [number_of_times_each_philosopher_must_eat]
int	main(int ac, char **av)
{
	if (input_parser(ac, av))
	{
		// 1) Check errors, filling table table
		// input_parser()

		// 2) Create the data
		// init_philo()

		//	3) Run the dinner
		// run_philo()

		// 4) Control leaks
		// free_philo()
	}
	else
		return (usage_err_msg(), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
- pthread_create(thread_ptr, attr, routine, arg)
* Spawns a new thread that immediately runs the 'routine' function.
* Connection: Used to birth a philosopher who runs their lifecycle loop.

- pthread_join(thread, retval_ptr)
* Blocks the current thread until the specific 'thread' finishes.
* Connection: Main thread uses this to wait for all philosophers before exiting.

- pthread_detach(thread)
* Tells OS to reclaim thread resources automatically on finish; prevents joining.
* Connection: sometimes used for the death-monitoring thread to run independently.


- pthread_mutex_init(mutex_ptr, attr)
* Initializes a mutex object so it can be locked/unlocked.
* Connection: Turns a variable into a usable 'fork' before simulation starts.

- pthread_mutex_lock(mutex_ptr)
* Tries to take the lock; if taken, the thread waits/blocks until available.
* Connection: A philosopher taking a fork or protecting the print function.

- pthread_mutex_unlock(mutex_ptr)
* Releases the lock so other waiting threads can acquire it.
* Connection: A philosopher putting down a fork after eating.

- pthread_mutex_destroy(mutex_ptr)
* Invalidates the mutex and frees its resources (must be unlocked).
* Connection: Cleaning up forks/locks at the very end to prevent leaks.
*/

void	init_philos(t_data *data)
{
	t_philo	*philos;
	long	i;

	i = 0;
	philos = malloc(sizeof(t_philo) * data->num_philo);
	while (i < data->num_philo)
	{
		data->philos[i] = philo_init(data);
		i++;
	}
}

t_philo	philo_init(t_data *data)
{
	t_philo philo;
	t_trd 	*th;

	pthread_create(th, NULL, routine, arg);
	philo.trd = th;
}

void	assign_forks(t_data *data);
