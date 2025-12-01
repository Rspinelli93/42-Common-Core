/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:11:55 by rick              #+#    #+#             */
/*   Updated: 2025/12/01 23:25:38 by rick             ###   ########.fr       */
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
/* memset */
#include <string.h>
/* printf */
#include <stdio.h>
/* malloc, free */
#include <stdlib.h>
/* write, usleep */
#include <unistd.h>
/* gettimeofday */
#include <sys/time.h>
/* pthread_create, pthread_detach, pthread_join, */
/* pthread_mutex_init, pthread_mutex_destroy, */
/* pthread_mutex_lock, pthread_mutex_unlock */
#include <pthread.h>
/*INT_MAX*/
#include <limits.h>

// ------------- STRUCTS ----------------

typedef struct s_data t_data;
typedef struct s_philo t_philo;
typedef struct s_fork t_fork;

struct s_data
{
	long	n_philo;
	long	t_die;
	long	t_eat;
	long	t_sleep;
	long	num_eat;

};

struct s_philo
{
	int a;
};

struct s_fork
{
	int ix;
	
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