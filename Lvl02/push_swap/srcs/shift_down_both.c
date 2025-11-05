/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_down_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:03:37 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/05 16:23:13 by rspinell         ###   ########.fr       */
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
	ft_printf("rrr\n");
}
