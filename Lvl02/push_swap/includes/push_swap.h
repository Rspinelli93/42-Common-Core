/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 12:06:31 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/03 12:10:01 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"

void	pa(t_list **head);
void	pb(t_list **head);
void	ra(t_list **head);
void	rb(t_list **head);
void	rr(t_list **head);
void	rra(t_list **head);
void	rrb(t_list **head);
void	swap_both(t_list **head_a, t_list **head_b);
void	swap_ab(t_list **head);

#endif
