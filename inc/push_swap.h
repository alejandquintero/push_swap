/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:28:04 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/18 23:07:08 by aquinter         ###   ########.fr       */
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
	int				number;
	struct s_stack	*next;
} t_stack;

void	sa(t_stack **a);
void	ra(t_stack **a);
void	rra(t_stack **a);
void    ft_lstadd_front(t_stack **lst, t_stack *new);
void    ft_lstadd_back(t_stack **lst, t_stack *new);
void    ft_lstdelone(t_stack *lst);
void    ft_lstclear(t_stack **lst);
// void    ft_lstiter(t_stack *lst, void (*f)(void *));
t_stack	*ft_lstnew(int number);
t_stack	*ft_lstlast(t_stack *lst);
// t_stack	*ft_lstmap(t_stack *lst, void *(*f)(void *), void (*del)(void *));
void print_stacks(t_stack *a, t_stack *b);
void	s(t_stack **s);
void	r(t_stack **s);
void	rr(t_stack **s);

#endif