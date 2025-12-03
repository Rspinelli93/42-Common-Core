/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:21:02 by rick              #+#    #+#             */
/*   Updated: 2025/12/02 19:14:19 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2
// https://www.youtube.com/watch?v=oq29KUy29iQ&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=4

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