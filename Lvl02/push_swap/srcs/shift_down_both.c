/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:03:37 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/03 14:43:43 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
+ rrr : (rotate reverse a) and (rotate reverse b) at the same time.
+ The last element becomes the first one.*/
void	shift_down_both(t_list **head1, t_list **head2)
{
    shift_down(head1);
    shift_down(head2);
}