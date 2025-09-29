/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 21:12:13 by rspinell          #+#    #+#             */
/*   Updated: 2025/09/15 21:12:14 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char* arr;
    size_t i;
    unsigned char* cdest;
    unsigned char* csrc;

    arr = (unsigned char*)malloc(sizeof(unsigned char) * n);
    i = 0;
    cdest = (unsigned char*)dest;
    csrc = (unsigned char*)src;
    while (i < n)
    {
        arr[i] = csrc[i];
        i++;
    }
    i = 0;
    while (i < n)
    {
        cdest[i] = arr[i];
        i++;
    }
    free(arr);
    return (dest);
}