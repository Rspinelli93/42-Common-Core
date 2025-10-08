/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 18:54:20 by rick              #+#    #+#             */
/*   Updated: 2025/10/08 21:59:33 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int     ft_printf(const char *format, ...);
void	ft_putchar_pf(char c, int *cnt);
void	ft_putstr_pf(char *str, int *cnt);
void	ft_printptr_pf(void *ptr, char *str, int *cnt);
void	ft_putnbr_pf(int i, int fd, int *cnt);
void	ft_putunsig_pf(unsigned int u, int *cnt);
void	ft_printhex_pf(unsigned int u, char *str, int *cnt);

#endif
