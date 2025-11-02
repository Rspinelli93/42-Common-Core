
//* cc ./main.c ./push_swaplib.a -I ./includes -o test

#include "push_swap.h"
#include "libft.h"

int	del(int *x);

int	main(void)
{
	t_list  list1;
	t_list  list2;
	t_list  list3;
	t_list  list4;
	t_list  list5;
	t_list  list6;
    t_list  *head;
    t_list  *poanteg;
	int	arr[6] = {12, 1, 9, 8, 19, -6};

	list1.cont = arr[0];
	list2.cont = arr[1];
	list3.cont = arr[2];
	list4.cont = arr[3];
	list5.cont = arr[4];
	list6.cont = arr[5];

	list3.next = &list2;
	list2.next = &list6;
	list6.next = &list4;
	list4.next = &list5;
	list5.next = &list1;
	list1.next = NULL;

    head = &list3;
	poanteg = head;
	//ft_lstdelone(&list1, &(del)(list1.cont));
    while (poanteg)
    {
        ft_printf("%i\n", poanteg->cont);
        poanteg = poanteg->next;
    }
}


/*
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, int (*del)(int));
void	ft_lstclear(t_list **lst, int (*del)(int));
void	ft_lstiter(t_list *lst, int (*f)(int));
t_list	*ft_lstmap(t_list *lst, int (*f)(int), int (*del)(int));
*/