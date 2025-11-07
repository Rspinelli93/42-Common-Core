/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:36:23 by rick              #+#    #+#             */
/*   Updated: 2025/11/07 20:41:50 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
+ This function takes an array and creates a linked list
+ allocating each node and setting the content of each 
+ node to each number of each possition in the array.
+
+ The return value is a pointer to the first node.*/
t_list	*mklist(int ac, char **arr)
{
	int		i;
	t_list	*head;

	i = 1;
	head = ft_lstnew(ft_atoi(arr[0]));
	if (ac == 2)
	{
		while (arr[i])
		{
			ft_lstadd_back(&head, ft_lstnew(ft_atoi(arr[i])));
			i++;
		}
	}
	else
	{
		while (i < ac - 1)
		{
			ft_lstadd_back(&head, ft_lstnew(ft_atoi(arr[i])));
			i++;
		}
	}
	return (head);
}

/*
+ Prints the content of each node with a \n after.*/
void	print_list(t_list *head)
{
	while (head)
	{
		ft_printf("%i\n", head->cont);
		head = head->next;
	}
}

/*
+ Return a pointer to the max or min cont node
+ Use 1 for max and 0 for min.*/
t_list	*find_min_max(t_list **list, const int a)
{
	t_list	*ptr;
	t_list	*temp;

	ptr = *list;
	temp = *list;
	if (a == 1)
	{
		while (temp)
		{
			if (ptr->cont < temp->cont)
				ptr = temp;
			temp = temp->next;
		}
		return (ptr);
	}
	else
	{
		while (temp)
		{
			if (ptr->cont > temp->cont)
				ptr = temp;
			temp = temp->next;
		}
		return (ptr);
	}
}

/*
+ Set the index and the media for each node of the list
+ ft_printf("index: %i - media: %i",ptr->index, ptr->media);
*/
void	set_index_media(t_list **list)
{
	int		i;
	int		med;
	t_list	*ptr;

	med = ft_lstsize(*list) / 2;
	i = 0;
	if (!*list)
		return ;
	ptr = *list;
	while (ptr)
	{
		ptr->index = i;
		if (i <= med)
			ptr->media = 0;
		else
			ptr->media = 1;
		i++;
		ptr = ptr->next;
	}
}
void	sort_big(t_list **a, t_list **b);
/*
- push 2 to b (checking every time if there is 3 in a)
- while (length of a != 3)
	- set_tagetnode
	- push cheapest (doing so will organize them in descending order in b) (bringing each on top (check media for rotate or reverse rotate) and then sa)
		if cost 0 push directly
		if pushcost is the smallest push the first one you find
- now that i have 3 in a -> sort_tree(a)
- while (b has something)
	- set_tagetnode
	- push cheapest (bringing each on top (check media for rotate or reverse rotate) and then sa)
		if cost 0 push directly
		if pushcost is the smallest push the first one you find
check if sorted, otherwise ra or rra (media) (min on top)
*/

void	set_targetnode(t_list **a, t_list **b);
/*
- find the closest smaller (if pushing from a to b)
		if closest smaller not found, targer node is the max value
- find the closest bigger (if pushing from b to a)
		if closest bigger not found, targer node is the min value
*/

void	set_cost(t_list **a, t_list **b);
/*
- calculate the number of moves needed:
- Math:

	X operations to bring a node to the top of 'a'
		+
	X operations to bring this node target to top of 'b'
	--------------------------------------
	= push cost;

	To calculate this is with media (or index), either up or down rotate times
*/



