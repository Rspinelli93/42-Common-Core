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
