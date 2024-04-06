/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:19:58 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/06 18:43:26 by aquinter         ###   ########.fr       */
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

void	set_targets_node(t_stack **from, t_stack *to)
{
	t_stack *aux;
	
	aux = *from;
	while (aux)
	{
		aux->target = get_smaller_target_node(aux->nbr, to);
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

void	set_total_moves(t_stack **from, int from_nbr, t_stack **to, int to_nbr)
{
	t_stack *node;
	t_stack *aux_from = *from;
	t_stack *aux_to = *to;
	int		len;
	int		moves;

	moves = 0;
 	node = find_by_nbr(aux_from, from_nbr);
	len = stack_len(aux_from);
	while (node->index != 0)	
	{
		if (node->index < len / 2)
			rotate(&aux_from);
		else
			reverse(&aux_from);
		save_index_node(&aux_from);		
		moves++;
	 	node = find_by_nbr(aux_from, from_nbr);
	}
	(*from)->cost = moves;

	
	moves = 0;
	node = find_by_nbr(aux_to, to_nbr);
	len = stack_len(aux_to);
	while (node->index != 0)	
	{
		if (node->index < len / 2)
			rotate(&aux_to);
		else
			reverse(&aux_to);
		save_index_node(&aux_to);
		moves++;
	 	node = find_by_nbr(aux_to, to_nbr);
	}
	(*to)->cost = moves;
}

void	push_cheapest_node(t_stack **from, t_stack **to)
{
	// t_stack *aux;

	// aux = *from;

	while (*from != NULL)
	{
		set_total_moves(from, (*from)->nbr, to, (*from)->target->nbr);
		ft_printf("moves to top: %d (%d) target:  %d (%d) \n", (*from)->nbr, (*from)->cost, (*from)->target->nbr, (*from)->target->cost );
		*from = (*from)->next;
	}
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