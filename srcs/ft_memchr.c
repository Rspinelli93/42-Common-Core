/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 21:11:51 by rspinell          #+#    #+#             */
/*   Updated: 2025/09/22 15:14:50 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char *ptr;
    
    ptr = (unsigned char*)s;
    while (n > 0 && ptr)
    {
        if (*ptr == c)
            return (ptr);
        ptr++;
        n--;
    }
    ptr = NULL;
    return (ptr);
}