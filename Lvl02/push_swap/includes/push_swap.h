/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 12:06:31 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/10 15:22:29 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"

// Bool
int		are_atoi(int size, char **arr);
int		is_sorted(t_list **list);

// Sorting
void	sort_three(t_list **list);
void	sort_two(t_list **list);
void	cheapest_to_top(t_list **src, t_list **dst, int x, int y);
void	sort_big(t_list **a, t_list **b);

// Utils
t_list	*mklist(int ac, char **arr);
void	print_list(t_list *list);
t_list	*find_min_max(t_list **list, const int a);
void	update_values_b(t_list **a, t_list **b);
void	update_values_a(t_list **a, t_list **b);

// Free
void	free_list(t_list *list);
void	free_split(char **arr);

// Update values
void	set_index_media(t_list **list);
void	set_target_atob(t_list **a, t_list **b);
void	set_target_btoa(t_list **b, t_list **a);
void	set_cost(t_list	**node, t_list **target, int med, int tmed);
void	set_cost_all(t_list **list);
t_list	*set_cheapest(t_list **list);

// Operations
void	push_top(t_list **src, t_list **dst, int x);
void	rotate(t_list **list, int x);
void	rotate_both(t_list **a, t_list **b);
void	reverse_rotate(t_list **list, int x);
void	reverse_rotate_both(t_list **a, t_list **b);
void	swap_ab(t_list **list, int x);
void	swap_both(t_list **a, t_list **b);

// tbd
void	to_top(t_list **src, t_list **dst, int x, int y);
void	to_top_index(t_list **src, t_list **dst, int x, int y);
void	to_top_media(t_list **src, t_list **dst, int x, int y);

t_list	*get_cheapest(t_list **list);

#endif
