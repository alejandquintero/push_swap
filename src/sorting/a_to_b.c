/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:51:36 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/20 17:22:09 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack	*find_by_nbr(t_stack *s, int nbr)
{
	t_stack	*node;

	node = NULL;
	if (s != NULL)
	{
		while (s != NULL && node == NULL)
		{
			if (s->nbr == nbr)
				node = s;
			s = s->next;
		}
	}
	return (node);
}

void	set_target_nodes_of_a(t_stack *a, t_stack *b)
{
	int		dist;
	long	shortest_dist;
	t_stack	*current_b;

	while (a)
	{
		current_b = b;
		shortest_dist = LONG_MAX;
		while (current_b != NULL)
		{
			if (a->nbr > current_b->nbr)
			{
				dist = a->nbr - current_b->nbr;
				if (dist < shortest_dist)
				{
					shortest_dist = dist;
					a->target = current_b;
				}
			}
			current_b = current_b->next;
		}
		if (shortest_dist == LONG_MAX)
			a->target = get_max_node(b);
		a = a->next;
	}
}

t_stack	*get_cheapest_node(t_stack *a, int len_a, int len_b)
{
	int		moves;
	long	min_moves;
	t_stack	*cheapest;

	min_moves = LONG_MAX;
	while (a != NULL)
	{
		moves = a->index;
		if (a->median == BELOW)
			moves = len_a - a->index;
		if (a->target->median == BELOW)
			moves += len_b - a->target->index;
		else
			moves += a->target->index;
		if (moves == 0)
			return (a);
		else if (moves < min_moves)
		{
			min_moves = moves;
			cheapest = a;
		}
		a = a->next;
	}
	return (cheapest);
}

void	push_cheapest_node_to_b(t_stack **a, t_stack **b, int nbr)
{
	t_stack	*cheapest_node;

	cheapest_node = find_by_nbr(*a, nbr);
	if (cheapest_node->median == cheapest_node->target->median)
	{
		while (*a != cheapest_node && *b != cheapest_node->target)
		{
			if (cheapest_node->median == ABOVE)
				rr(a, b);
			else
				rrr(a, b);
		}
	}
	move_to_top(a, cheapest_node, 'a');
	move_to_top(b, cheapest_node->target, 'b');
	pb(a, b);
}
