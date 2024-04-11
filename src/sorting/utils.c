/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:19:58 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/11 23:50:31 by aquinter         ###   ########.fr       */
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
	int		shortest_dist;
	int		dist;

	target = NULL;
	shortest_dist = 0;
	aux = s;
	if (aux != NULL)
	{
		while (aux != NULL)
		{
			if (nbr > aux->nbr)
			{
				dist = nbr - aux->nbr;
				if (shortest_dist == 0 || dist < shortest_dist)
				{
					shortest_dist = dist;
					target = aux;
				}
			}
			aux = aux->next;
		}
		if (shortest_dist == 0)
			target = get_max_node(s);
	}
	return (target);
}

t_stack	*get_bigger_target_node(int nbr, t_stack *s)
{
	t_stack	*target;
	t_stack	*aux;
	int		shortest_dist;
	int		dist;

	target = NULL;
	shortest_dist = 0;
	aux = s;
	if (aux != NULL)
	{
		while (aux != NULL)
		{
			if (nbr < aux->nbr)
			{
				dist = aux->nbr - nbr;
				if (shortest_dist == 0 || dist < shortest_dist)
				{
					shortest_dist = dist;
					target = aux;
				}
			}
			aux = aux->next;
		}
		if (shortest_dist == 0)
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

int	get_total_moves(t_stack *node, int s_length, int t_length)
{
	int moves;
	int s_position;
	int t_position;

	moves = 0;
	s_position = -1;
	t_position = -1;
	if (node->index > 0)
	{
		s_position = get_median(node, s_length);
		if (s_position == ABOVE)
			moves = node->index;
		else
			moves = s_length - node->index;
	}
	if (node->target->index > 0)
	{
		t_position = get_median(node->target, t_length);
		if (t_position == ABOVE)
			moves += node->target->index;
		else
			moves += t_length - node->target->index;
	}
	if (s_position == t_position)
	{
		if (moves % 2 != 0)
			moves = (moves + 1) / 2;
		else
			moves = moves / 2;			
	}
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
		// ft_printf("moves to top: %d", aux->nbr);
		// ft_printf(" target %d : ", aux->target->nbr);
		// ft_printf("%d\n", moves);
		aux = aux->next;
	}
	return (cheapest_node);
}

void	push_cheapest_node(t_stack **s_source, t_stack **s_target, int nbr)
{
	t_stack *node = find_by_nbr(*s_source, nbr);
	t_stack *target_node = find_by_nbr(*s_target, node->target->nbr);
	
	int node_position;
	int target_position;

	node_position = -1;
	target_position = -1;
	while (node->index != 0 || node->target->index != 0)
	{
		node_position = get_median(node, len(*s_source));
		target_position = get_median(node->target, len(*s_target));

		if (node_position == target_position && node->index != 0 && target_node->index != 0)
		{
			if (node_position == ABOVE)
				rr(s_source, s_target);
			else
				rrr(s_source, s_target);
		}
		else
		{
			if (node->index > 0)
			{
				if (node_position == ABOVE)
					ra(s_source);
				else
					rra(s_source);
			}
			if (node->target->index > 0)
			{
				if (target_position == ABOVE)
					rb(s_target);
				else
					rrb(s_target);
			}
		}
		node = find_by_nbr(*s_source, nbr);
		target_node = find_by_nbr(*s_target, node->target->nbr);
	}
	pb(s_source, s_target);
}

void	push_cheapest_node_desc(t_stack **s_source, t_stack **s_target, int nbr)
{
	t_stack *node = find_by_nbr(*s_source, nbr);
	t_stack *target_node = find_by_nbr(*s_target, node->target->nbr);
	
	int node_position;
	int target_position;

	node_position = -1;
	target_position = -1;
	while (node->index != 0 || node->target->index != 0)
	{
		node_position = get_median(node, len(*s_source));
		target_position = get_median(node->target, len(*s_target));

		if (node_position == target_position && node->index != 0 && target_node->index != 0)
		{
			if (node_position == ABOVE)
				rr(s_source, s_target);
			else
				rrr(s_source, s_target);
		}
		else
		{
			if (node->index > 0)
			{
				if (node_position == ABOVE)
					rb(s_source);
				else
					rrb(s_source);
			}
			if (node->target->index > 0)
			{
				if (target_position == ABOVE)
					ra(s_target);
				else
					rra(s_target);
			}
		}
		node = find_by_nbr(*s_source, nbr);
		target_node = find_by_nbr(*s_target, node->target->nbr);
	}
	pa(s_source, s_target);
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