/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 21:12:06 by rspinell          #+#    #+#             */
/*   Updated: 2025/09/22 21:07:05 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    char* s;
    char* d;
    size_t i;

    s = (char*)src;
    d = (char*)dest;
    i = 0;
    while (i < n)
    {
        *d = *s;
        i++;
        s++;
        d++;
    }
    return (dest);
}