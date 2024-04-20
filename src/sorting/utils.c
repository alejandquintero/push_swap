/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:19:58 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/20 17:19:09 by aquinter         ###   ########.fr       */
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
