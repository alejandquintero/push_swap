/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:44:23 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/18 22:10:23 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_n(t_stack **a, t_stack **b)
{
	int		len_stack_a;
	t_stack	*min_node;

	len_stack_a = stack_length(*a);
	if (len_stack_a-- > 3 && !is_sorted(*a))
		pb(a, b);
	if (len_stack_a-- > 3 && !is_sorted(*a))
		pb(a, b);
	while (len_stack_a-- > 3 && !is_sorted(*a))
	{
		set_median(*a);
		set_median(*b);
		set_targets_node_a(*a, *b);
		push_cheapest_node_to_b(a, b, get_cheapest_node(*a, *b)->nbr);
	}
	if (!is_sorted(*a))
		sort_three(a);
	while (*b != NULL)
	{
		set_median(*a);
		set_targets_node_b(*b, *a);
		push_b_to_a(b, a);
	}
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
