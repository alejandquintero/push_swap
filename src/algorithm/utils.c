/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:19:58 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/06 00:01:59 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack *get_min_node(t_stack *s)
{
	t_stack *min;

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

t_stack *get_max_node(t_stack *s)
{
	t_stack *max;

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

t_stack *get_smaller_target_node(int nbr, t_stack *s)
{
	t_stack *target;
	t_stack *aux;
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

t_stack *get_bigger_target_node(int nbr, t_stack *s)
{
	t_stack *target;
	t_stack *aux;
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
// t_stack get_last_node(t_stack *s)