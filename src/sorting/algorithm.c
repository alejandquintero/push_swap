/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:44:23 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/20 17:28:43 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;
	int		len_a;
	int		len_b;

	len_a = stack_length(*a);
	len_b = stack_length(*b);
	set_median(*a);
	set_median(*b);
	set_target_nodes_of_a(*a, *b);
	cheapest_node = get_cheapest_node(*a, len_a, len_b);
	push_cheapest_node_to_b(a, b, cheapest_node->nbr);
}

void	push_to_a(t_stack **a, t_stack **b)
{
	set_median(*a);
	set_target_nodes_of_b(*b, *a);
	push_b_to_a(b, a);
}

void	move_min_node_to_top(t_stack **a)
{
	t_stack	*min_node;

	set_median(*a);
	min_node = get_min_node(*a);
	while ((*a)->nbr != min_node->nbr)
	{
		if (min_node->median == ABOVE)
			ra(a, true);
		else
			rra(a, true);
	}
}

void	sort_n(t_stack **a, t_stack **b)
{
	int		len_a;

	len_a = stack_length(*a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(a, b);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(a, b);
	while (len_a-- > 3 && !is_sorted(*a))
		push_to_b(a, b);
	if (!is_sorted(*a))
		sort_three(a);
	while (*b != NULL)
		push_to_a(a, b);
	move_min_node_to_top(a);
}
