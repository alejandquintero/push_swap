/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:19:58 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/18 22:25:34 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack	*get_min_node(t_stack *s)
{
	t_stack	*min;

	min = NULL;
	if (s != NULL)
	{
		min = s;
		s = s->next;
		while (s != NULL)
		{
			if (s->nbr < min->nbr)
				min = s;
			s = s->next;
		}
	}
	return (min);
}

t_stack	*get_max_node(t_stack *s)
{
	t_stack	*max;

	max = NULL;
	if (s != NULL)
	{
		max = s;
		s = s->next;
		while (s != NULL)
		{
			if (s->nbr > max->nbr)
				max = s;
			s = s->next;
		}
	}
	return (max);
}

void	set_targets_node_a(t_stack *a, t_stack *b)
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

void	set_targets_node_b(t_stack *b, t_stack *a)
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

void	set_median(t_stack *stack)
{
	int	len;

	if (stack)
	{
		len = stack_length(stack);
		while (stack != NULL)
		{
			if (stack->index <= (len / 2))
				stack->median = ABOVE;
			else
				stack->median = BELOW;
			stack = stack->next;
		}
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

void	move_to_top(t_stack **s, t_stack *node, char stack)
{
	while (*s != node)
	{
		if (node->index > 0)
		{
			if (node->median == ABOVE)
			{
				if (stack == 'a')
					ra(s, true);
				else
					rb(s, true);
			}
			else
			{
				if (stack == 'a')
					rra(s, true);
				else
					rrb(s, true);
			}
		}
	}
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

void	save_index_node(t_stack **s)
{
	int		i;
	t_stack	*aux;

	i = 0;
	aux = *s;
	while (aux != NULL)
	{
		aux->index = i;
		i++;
		aux = aux->next;
	}
}
