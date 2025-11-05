/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:35:41 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/05 14:05:17 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//* cc ./push_swap.c ./push_swaplib.a -I ./includes -o test

#include "push_swap.h"

void	sort_three(t_list **first);

int	main(int argc, char **argv)
{
	t_list	*head_a;

	if (!are_atoi(argc, argv))
		return (-1);
	head_a = mklist(argc, argv);
	print_list(head_a);
	ft_printf("\n");
	if (argc == 4)
		sort_three(&head_a);
	print_list(head_a);
	ft_lstclear(&head_a, &del);
	return (0);
}

// sort 3 numbers

void	sort_three(t_list **first)
{
	t_list	*sec;
	t_list	*thrd;

	sec = (*first)->next;
	thrd = ft_lstlast((*first));
	if (((*first)->cont < sec->cont) && (sec->cont < thrd->cont))
		return ;
	else if (((*first)->cont > sec->cont) && (sec->cont < thrd->cont))
		swap_ab(first);
	else if (((*first)->cont < sec->cont) && (sec->cont > thrd->cont))
	{
		swap_ab(first);
		shift_up(first);
	}
	else
	{
		swap_ab(first);
		shift_down(first);
	}
}