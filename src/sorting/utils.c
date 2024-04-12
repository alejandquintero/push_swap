/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:19:58 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/12 23:29:06 by aquinter         ###   ########.fr       */
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

t_stack	*get_smaller_target_node(int nbr, t_stack *s)
{
	t_stack	*target;
	t_stack	*aux;
	long	shortest_dist;
	int		dist;

	target = NULL;
	shortest_dist = LONG_MAX;
	aux = s;
	if (aux != NULL)
	{
		while (aux != NULL)
		{
			if (nbr > aux->nbr)
			{
				dist = nbr - aux->nbr;
				if (dist < shortest_dist)
				{
					shortest_dist = dist;
					target = aux;
				}
			}
			aux = aux->next;
		}
		if (shortest_dist == LONG_MAX)
			target = get_max_node(s);
	}
	return (target);
}

t_stack	*get_bigger_target_node(int nbr, t_stack *s)
{
	t_stack	*target;
	t_stack	*aux;
	long	shortest_dist;
	int		dist;

	target = NULL;
	shortest_dist = LONG_MAX;
	aux = s;
	if (aux != NULL)
	{
		while (aux != NULL)
		{
			if (nbr < aux->nbr)
			{
				dist = aux->nbr - nbr;
				if (dist < shortest_dist)
				{
					shortest_dist = dist;
					target = aux;
				}
			}
			aux = aux->next;
		}
		if (shortest_dist == LONG_MAX)
			target = get_min_node(s);
	}
	return (target);
}

void	set_targets_node(t_stack **s_source, t_stack *s_target, bool smaller)
{
	t_stack *aux;
	
	aux = *s_source;
	while (aux)
	{
		if (smaller)
			aux->target = get_smaller_target_node(aux->nbr, s_target);
		else
			aux->target = get_bigger_target_node(aux->nbr, s_target);
		aux = aux->next;
	}
}

t_stack	*find_by_nbr(t_stack *s, int nbr)
{
	t_stack *node;
	
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

int	get_median(t_stack *node, int stack_length)
{
	if (node->index <= stack_length / 2)
		return (ABOVE);
	return (BELOW);
}

int	get_total_moves(t_stack *node, int source_length, int target_length)
{
	int moves;
	int node_position;
	int target_position;

	moves = 0;
	node_position = get_median(node, source_length);
	target_position = get_median(node->target, target_length);
	
	moves = node->index;
	if (node_position == BELOW)
		moves = source_length - node->index;
	if (target_position == BELOW)
		moves += target_length - node->target->index;
	else
		moves += node->target->index;
	return (moves);
}

t_stack	*find_cheapest_node(t_stack *s_source, t_stack *s_target)
{
	t_stack *aux;
	t_stack *cheapest_node;
	int s_length;
	int t_length;
	int moves;
	long min_moves;
	
	s_length = len(s_source);
	t_length = len(s_target);
	aux = s_source;
	min_moves = LONG_MAX;
	while (aux != NULL)
	{
		moves = get_total_moves(aux, s_length, t_length);
		if (moves == 0)
			return (aux);
		else if (moves < min_moves)
		{
			min_moves = moves,
			cheapest_node = aux;
		}
		aux = aux->next;
	}
	return (cheapest_node);
}

void move_to_top(t_stack **s, t_stack *node, char stack)
{
	int	node_position;

	node_position = get_median(node, len(*s));
	while (*s != node)
	{
		if (node->index > 0)
		{
			if (node_position == ABOVE)
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
	t_stack *cheapest_node = find_by_nbr(*a, nbr);
	int node_position;
	int target_position;

	node_position = get_median(cheapest_node, len(*a));
	target_position = get_median(cheapest_node->target, len(*b));
	if (node_position ==  target_position)
	{
		while (*a != cheapest_node && *b != cheapest_node->target)
		{
			if (node_position == ABOVE)
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
	t_stack *node;
	int		target_position;
	
	node = *b;
	target_position = get_median(node->target, len(*a));
	while (*a != node->target)
	{
		if (node->target->index > 0)
		{
			if (target_position == ABOVE)
				ra(a, true);
			else
				rra(a, true);
		}
	}
	pa(b, a);
}


void	save_index_node(t_stack **s)
{
	int	i;
	t_stack *aux;

	i = 0;
	aux = *s;
	while (aux != NULL)
	{
		aux->index = i;
		i++;
        aux = aux->next;
	}
}