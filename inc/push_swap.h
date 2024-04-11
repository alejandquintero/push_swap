/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:28:04 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/12 00:14:25 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# define ABOVE 0
# define BELOW 1

# include <stdbool.h>
# include <limits.h>
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"

typedef struct s_stack
{
	int				nbr;
	int 			index;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

t_stack	*stack_last(t_stack *lst);
t_stack	*stack_new(int number, int index);
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
void	sort_three(t_stack **s);
void	print_sorted_stack(t_stack *a);
void	exec(t_stack **s, char *movement, char stack);
bool	is_sorted(t_stack *s);
t_stack	*get_min_node(t_stack *s);
t_stack	*get_max_node(t_stack *s);
t_stack	*get_smaller_target_node(int nbr, t_stack *s);
t_stack	*get_bigger_target_node(int nbr, t_stack *s);
t_stack	*find_cheapest_node(t_stack *s_source, t_stack *s_target);
int		len(t_stack *s);
void	sort(t_stack **a, t_stack **b);
void	sort_two(t_stack **s);
void	sort_n(t_stack **a, t_stack **b);
void	save_index_node(t_stack **s);
void	set_targets_node(t_stack **s_source, t_stack *s_target, bool smaller);
t_stack	*find_by_nbr(t_stack *s, int nbr);
void	push_cheapest_node(t_stack **s_source, t_stack **s_target, int nbr);
void	push_cheapest_node_desc(t_stack **s_source, t_stack **s_target, int nbr);
int		get_median(t_stack *node, int stack_length);

#endif
