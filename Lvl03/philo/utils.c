/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:36:03 by rick              #+#    #+#             */
/*   Updated: 2025/12/01 22:48:22 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *safe_malloc(size_t bytes)
{
    void    *ret;

    ret = malloc(bytes);
    if (!ret)
    {
        //*free_philo();
        exit_msg("Malloc Error.\n");
    }
    return (ret);
}
