/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:19:58 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/28 23:21:04 by aquinter         ###   ########.fr       */
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

t_stack *get_target_node(int nbr, t_stack *s)
{
	t_stack *target;
	int		shortest_dist;
	int		dist;
	
	target = NULL;
	shortest_dist = 0;
	if (s != NULL)
	{
		while (s != NULL)
		{
			dist = nbr - s->nbr;
			// ft_printf("\ndist %d\n", dist);

			if (dist < 0)
			{
				// Bigger
			}
			else
			{
				if ((shortest_dist == 0 && dist > 0) ||
					(dist < shortest_dist))
				{
					shortest_dist = dist;
					target = s;
					// ft_printf("\naqui 1 %d\n", target->nbr);
					
				}
			}
			s = s->next;
		}
		
	}
	// ft_printf("\nreturn target 1 %d\n", target->nbr);
	return (target);	
}
// t_stack get_last_node(t_stack *s)