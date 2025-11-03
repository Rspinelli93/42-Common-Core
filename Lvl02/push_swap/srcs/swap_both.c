/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:01:58 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/03 12:08:20 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
+ ss : (swap a) and (swap b) at the same time. */
void	swap_both(t_list **head_a, t_list **head_b)
{
    swap_ab(head_a);
    swap_ab(head_b);
}