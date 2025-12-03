/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:11:55 by rick              #+#    #+#             */
/*   Updated: 2025/12/03 14:59:06 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// ------------- DEFINES ----------------

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define RESET   "\033[0m"

// ------------- INCLUDES ----------------

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <limits.h>

// ------------- STRUCTS ----------------

typedef struct s_data t_data;
typedef struct s_philo t_philo;
typedef struct s_fork t_fork;
typedef pthread_mutex_t t_mutex;
typedef pthread_t t_thread;

struct s_data
{
	long	num_philo;
	long	tm_die;
	long	tm_eat;
	long	tm_sleep;
	long	num_eat;
	t_fork	*forks;
	t_philo	*philos;
};

struct s_philo
{
	t_thread	*trd;
};

struct s_fork
{
	t_mutex	*mtx;
	int		ix;
};

// ------------- PROTOTYPES ----------------

//* ------ exit.c ------ //
void	exit_msg(char *msg);
void	usage_err_msg(void);

//* ------ init.c ------ //

//* ------ main.c ------ //

//* ------ parse.c ------ //
int		input_parser(int ac, char **av);
long	ft_atol(char *str);

//* ------ run.c ------ //

//* ------ utils.c ------ //
void    *safe_malloc(size_t bytes);

#endif