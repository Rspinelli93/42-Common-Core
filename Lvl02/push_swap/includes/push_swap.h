/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 12:06:31 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/03 14:43:09 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"

void	push_top(t_list **h_srcs, t_list **h_dest);
void	shift_up(t_list **head);
void	shift_up_both(t_list **head1, t_list **head2);
void	shift_down(t_list **list);
void	shift_down_both(t_list **head1, t_list **head2);
void	swap_ab(t_list **head);
void	swap_both(t_list **head_a, t_list **head_b);

#endif
