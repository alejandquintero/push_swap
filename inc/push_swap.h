/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:28:04 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/30 21:29:50 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ABOVE 0
# define BELOW 1
# define MIN_ARGUMENTS 2

# include <stdbool.h>
# include <limits.h>
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				median;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

t_stack	*stack_last(t_stack *lst);
t_stack	*stack_new(int number);
t_stack	*get_min_node(t_stack *s);
t_stack	*get_max_node(t_stack *s);
t_stack	*get_cheapest_node(t_stack *a, int len_a, int len_b);
bool	is_sorted(t_stack *s);
int		stack_length(t_stack *s);
void	sa(t_stack **a);
void	ra(t_stack **a, bool print);
void	rra(t_stack **a, bool print);
void	pa(t_stack **b, t_stack **a);
void	sb(t_stack **b);
void	rb(t_stack **b, bool print);
void	rrb(t_stack **b, bool print);
void	pb(t_stack **a, t_stack **b);
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
void	sort_three(t_stack **s);
void	print_sorted_stack(t_stack *a);
void	sort(t_stack **a, t_stack **b);
void	sort_n(t_stack **a, t_stack **b);
void	save_index_node(t_stack **s);
void	push_cheapest_node_to_b(t_stack **a, t_stack **b, int nbr);
void	push_b_to_a(t_stack **b, t_stack **a);
void	set_median(t_stack *stack);
void	set_target_nodes_of_a(t_stack *a, t_stack *b);
void	set_target_nodes_of_b(t_stack *b, t_stack *a);
void	move_to_top(t_stack **s, t_stack *node, char stack);
void	free_nbrs(char **str);
void	error(char **nbrs, t_stack *a);

#endif
