/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 12:06:31 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/05 12:38:43 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"

int		are_atoi(int size, char **arr);
void	free_list(t_list *head);
t_list	*mklist(int ac, char **arr);
void	print_list(t_list *head);
void	push_top(t_list **h_srcs, t_list **h_dest);
void	shift_up(t_list **head);
void	shift_up_both(t_list **head1, t_list **head2);
void	shift_down(t_list **list);
void	shift_down_both(t_list **head1, t_list **head2);
void	swap_ab(t_list **head);
void	swap_both(t_list **head_a, t_list **head_b);

#endif
