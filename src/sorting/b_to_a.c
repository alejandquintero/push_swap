/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:53:55 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/20 16:55:03 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	set_target_nodes_of_b(t_stack *b, t_stack *a)
{
	int		dist;
	long	shortest_dist;
	t_stack	*current_a;

	while (b)
	{
		current_a = a;
		shortest_dist = LONG_MAX;
		while (current_a != NULL)
		{
			if (b->nbr < current_a->nbr)
			{
				dist = current_a->nbr - b->nbr;
				if (dist < shortest_dist)
				{
					shortest_dist = dist;
					b->target = current_a;
				}
			}
			current_a = current_a->next;
		}
		if (shortest_dist == LONG_MAX)
			b->target = get_min_node(a);
		b = b->next;
	}
}

void	push_b_to_a(t_stack **b, t_stack **a)
{
	t_stack	*node;

	node = *b;
	while (*a != node->target)
	{
		if (node->target->index > 0)
		{
			if (node->target->median == ABOVE)
				ra(a, true);
			else
				rra(a, true);
		}
	}
	pa(b, a);
}
