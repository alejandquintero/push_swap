/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:44:23 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/12 00:15:28 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_n(t_stack **a, t_stack **b)
{
	int stack_length;
	t_stack *cheapest_node;
	t_stack *min_node;
	int node_position;

	stack_length = len(*a);
	pb(a, b);
	if (stack_length != 4)
		pb(a, b);
	while (len(*a) != 3)
	{	
		set_targets_node(a, *b, true);
		cheapest_node = find_cheapest_node(*a, *b);
		// ft_printf("cheapest node: %d -> %d\n", cheapest_node->nbr, cheapest_node->target->nbr);
		push_cheapest_node(a, b, cheapest_node->nbr);
		// break;
	}
	if (!is_sorted(*a))
		sort_three(a);
	while (*b != NULL)
	{
		set_targets_node(b, *a, false);
		cheapest_node = find_cheapest_node(*b, *a);
		// ft_printf("cheapest node: %d -> %d\n", cheapest_node->nbr, cheapest_node->target->nbr);
		push_cheapest_node_desc(b, a, cheapest_node->nbr);
	}
 	min_node = get_min_node(*a);
	node_position = -1;
	while (min_node->index != 0)	
	{
		node_position = get_median(min_node, len(*a));
		if (node_position == ABOVE)
			ra(a);
		else
			rra(a);
	 	min_node = get_min_node(*a);
	}
}
