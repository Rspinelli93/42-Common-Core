/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 21:11:34 by rspinell          #+#    #+#             */
/*   Updated: 2025/09/22 14:30:44 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    void* ptr = malloc(nmemb * size);
    if (ptr == NULL)
        return (ptr);
    ft_bzero(ptr, nmemb * size);
    return (ptr);
}