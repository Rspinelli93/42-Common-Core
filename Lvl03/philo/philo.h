/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:11:55 by rick              #+#    #+#             */
/*   Updated: 2025/12/01 19:00:18 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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

// ------------- STRUCTS ----------------

typedef struct s_data;
typedef struct s_philo;
typedef struct s_fork;

struct s_data
{
}   t_data;

struct s_philo
{
}   t_philo;

struct s_fork
{
}   t_fork;

// ------------- PROTOTYPES ----------------

//* ------ exit.c ------ //

//* ------ init.c ------ //

//* ------ main.c ------ //

//* ------ parse.c ------ //

//* ------ run.c ------ //
#endif