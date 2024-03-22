/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:28:04 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/22 23:25:44 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int	ft_atoi(const char *str);
int	ft_isdigit(int c);

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
} t_stack;

t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int number);
void	sa(t_stack **a);
void	ra(t_stack **a);
void	rra(t_stack **a);
void	pa(t_stack **b, t_stack **a);
void	sb(t_stack **b);
void	rb(t_stack **b);
void	rrb(t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void    ft_lstadd_front(t_stack **lst, t_stack *new);
void    ft_lstadd_back(t_stack **lst, t_stack *new);
void    ft_lstdelone(t_stack *lst);
void    ft_lstclear(t_stack **lst);
void 	print_stacks(t_stack *a, t_stack *b);
void	swap(t_stack **s);
void	rotate(t_stack **s);
void	reverse(t_stack **s);
void	push(t_stack **from, t_stack **to);
bool 	is_sorted(t_stack *s);
void	sort_three(t_stack **s);


#endif