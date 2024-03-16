/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:28:04 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/16 22:36:20 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str);
int	ft_isdigit(int c);

typedef struct s_stack
{
	char			*content;
	struct s_stack	*next;
} t_stack;

typedef struct s_list
{
    int            number;
    struct s_list   *next;
}   t_list;

void    ft_lstadd_front(t_list **lst, t_list *new);
void    ft_lstadd_back(t_list **lst, t_list *new);
void    ft_lstdelone(t_list *lst, void (*del)(void*));
void    ft_lstclear(t_list **lst, void (*del)(void*));
void    ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstnew(int number);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif