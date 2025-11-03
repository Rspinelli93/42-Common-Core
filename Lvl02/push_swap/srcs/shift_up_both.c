/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_up_both.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:03:08 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/03 19:12:25 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
+ rr : (rotate a) and (rotate b) at the same time.
+ The first element becomes the last one.*/
void	shift_up_both(t_list **head1, t_list **head2)
{
	shift_up(head1);
	shift_up(head2);
}
