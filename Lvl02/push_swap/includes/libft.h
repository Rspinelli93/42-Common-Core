/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:31:12 by rspinell          #+#    #+#             */
/*   Updated: 2025/09/29 15:31:12 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_list
{
	int				cont;
	int				index;
	int				cost;
	int				media; //bool
	int				cheapest; //bool
	struct s_list	*target_node;
	struct s_list	*prev;	
	struct s_list	*next;
}	t_list;

long	ft_atoi(const char *nptr);
void	ft_bzero(void *s, int n);
void	*ft_calloc(int nmemb, int size);
int		ft_isdigit(int c);
char	*ft_strdup(const char *s);
int		ft_strlen(const char *s);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstiter(t_list *lst, void (*f)(int));
t_list	*ft_lstmap(t_list *lst, int (*f)(int));

void	del(int content);

#endif
