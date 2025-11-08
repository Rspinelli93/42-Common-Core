/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:36:23 by rick              #+#    #+#             */
/*   Updated: 2025/11/09 00:16:15 by rspinell         ###   ########.fr       */
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
		ft_printf("cont: %i\n", head->cont);
		if (head->target_node)
			ft_printf("target: %i\n", head->target_node->cont);
		ft_printf("\n");
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

/* TESTED
+ Find the closest smaller (if pushing from a to b)
+ If closest smaller not found, targer node is the max value.*/
void	set_target_atob(t_list **a, t_list **b)
{
	t_list	*pa;
	t_list	*pb;
	t_list	*temp;

	if (!*a || !*b)
		return ;
	pa = *a;
	while (pa)
	{
		pb = *b;
		temp = find_min_max(b, 0);
		while (pb)
		{
			if (pb->cont < pa->cont && pb->cont > temp->cont)
				temp = pb;
			pb = pb->next;
		}
		if (pa->cont < temp->cont)
			pa->target_node = find_min_max(b, 1);
		else
			pa->target_node = temp;
		pa = pa->next;
	}
}

/* TESTED
+ Find the closest bigger (if pushing from b to a)
+ If closest bigger not found, targer node is the min value */
void	set_target_btoa(t_list **b, t_list **a)
{
	t_list	*pa;
	t_list	*pb;
	t_list	*temp;

	if (!*a || !*b)
		return ;
	pb = *b;
	while (pb)
	{
		pa = *a;
		temp = find_min_max(a, 1);
		while (pa)
		{
			if (pa->cont > pb->cont && pa->cont < temp->cont)
				temp = pa;
			pa = pa->next;
		}
		if (pb->cont > temp->cont)
			pb->target_node = find_min_max(a, 0);
		else
			pb->target_node = temp;
		pb = pb->next;
	}
}

/*
- calculate the number of moves needed:
- Math:

	X operations to bring a node to the top of 'a'
		.+
	X operations to bring this node target to top of 'b'

	= push cost;

	To calculate this is with media (or index), either up or down rotate times
*/
void	set_cost(t_list	**node, t_list **a, t_list **b)
{
	int	nb;

	nb = 0;
	// Make bigger if statements here to separate by a list first, not repeating ifs params
	if ((*node)->media && (*node)->target_node->media)
	{
		if (ft_lstsize(*node) >= ft_lstsize((*node)->target_node)) //Both over media
			nb = ft_lstsize(*node) + 1;
		else
			nb = ft_lstsize((*node)->target_node) + 1;
	}
	else if (!(*node)->media && !(*node)->target_node->media) //Both under media
	{
		if ((*node)->index >= (*node)->target_node->index)
			nb = (*node)->index;
		else
			nb = (*node)->target_node->index;
	}
}



