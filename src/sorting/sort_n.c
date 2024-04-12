/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:44:23 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/12 23:29:22 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_n(t_stack **a, t_stack **b)
{
	t_stack *cheapest_node;
	int node_position;
	int	len_a = len(*a);
	
	if (len_a-- > 3 && !is_sorted(*a))
		pb(a, b);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(a, b);
	while (len_a-- > 3 && !is_sorted(*a))
	{	
		set_targets_node(a, *b, true);
		cheapest_node = find_cheapest_node(*a, *b);
		push_cheapest_node_to_b(a, b, cheapest_node->nbr);
	}
	if (!is_sorted(*a))
		sort_three(a);
	while (*b != NULL)
	{
		set_targets_node(b, *a, false);
		push_b_to_a(b, a);
	}
	node_position = get_median(get_min_node(*a), len(*a));
	while ((*a)->nbr != get_min_node(*a)->nbr)	
	{
		if (node_position == ABOVE)
			ra(a, true);
		else
			rra(a, true);
	}
}
