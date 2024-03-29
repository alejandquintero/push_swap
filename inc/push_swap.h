/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:28:04 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/25 22:23:43 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
}	t_stack;

t_stack	*stack_last(t_stack *lst);
t_stack	*stack_new(int number);
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
void	stack_add_front(t_stack **lst, t_stack *new);
void	stack_add_back(t_stack **lst, t_stack *new);
void	del_one(t_stack *lst);
void	stack_clear(t_stack **lst);
void	print_stacks(t_stack *a, t_stack *b);
void	swap(t_stack **s);
void	rotate(t_stack **s);
void	reverse(t_stack **s);
void	push(t_stack **from, t_stack **to);
void	sort_three(t_stack **s, char stack);
void	print_sorted_stack(t_stack *a);
void	exec(t_stack **s, char *movement, char stack);
bool	is_sorted(t_stack *s);

#endif
