/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 12:06:31 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/12 11:03:20 by rspinell         ###   ########.fr       */
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
void	sort_big(t_list **a, t_list **b);
void	sort_list(t_list **a, t_list **b);

// Sorting
void	cheapest_to_top_a(t_list **a, t_list **b);
void	atob_bot(t_list **a, t_list **b);
void	atob_top(t_list **a, t_list **b);
void	atob(t_list **a, t_list **b);
void	cheapest_to_top_b(t_list **b, t_list **a);
void	btoa_bot(t_list **b, t_list **a);
void	btoa_top(t_list **b, t_list **a);
void	btoa(t_list **b, t_list **a);

// Utils
t_list	*mklist(int ac, char **arr);
void	print_list(t_list *list);
t_list	*find_min_max(t_list **list, const int a);
void	update_values_b(t_list **a, t_list **b);
void	update_values_a(t_list **a, t_list **b);
int		arr_size(char **arr);

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
t_list	*get_cheapest(t_list **list);

// Operations
void	ra(t_list **list, int x);
void	rb(t_list **list, int x);
void	rr(t_list **a, t_list **b);
void	rrb(t_list **list, int x);
void	rra(t_list **list, int x);
void	rrr(t_list **a, t_list **b);
void	ss(t_list **a, t_list **b);
void	sb(t_list **list, int x);
void	sa(t_list **list, int x);
void	push_top(t_list **src, t_list **dst, int x);

#endif
