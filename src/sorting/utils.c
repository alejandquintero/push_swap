/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:19:58 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/10 00:22:18 by aquinter         ###   ########.fr       */
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

int	set_total_moves(t_stack *aux, int stack_to_len, int stack_from_len)
{
	int moves;

	moves = 0;
	if (aux->index > 0)
	{
		if (aux->index <= stack_from_len / 2)
			moves = aux->index;
		else
			moves = stack_from_len - aux->index;
	}
	if (aux->target->index > 0)
	{
		if (aux->target->index <= stack_to_len / 2)
			moves += aux->target->index;
		else
			moves += stack_to_len - aux->target->index;
	}
	return (moves);
}

void	push_cheapest_node(t_stack **from, t_stack **to)
{
	t_stack *aux;
	aux = *from;
	int stack_to_len = stack_len(*to);
	int stack_from_len = stack_len(*from);
	int moves;
	while (aux != NULL)
	{
		moves = set_total_moves(aux, stack_to_len, stack_from_len);
		ft_printf("moves to top: %d", aux->nbr);
		ft_printf(" target %d : ", aux->target->nbr);
		ft_printf("%d\n", moves);
		aux = aux->next;
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