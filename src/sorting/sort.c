/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:32:55 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/20 14:48:18 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

bool	is_sorted(t_stack *s)
{
	if (s != NULL)
	{
		while (s->next != NULL)
		{
			if (s->nbr > s->next->nbr)
				return (false);
			s = s->next;
		}
	}
	return (true);
}

void	sort_three(t_stack **s)
{
	int	a;
	int	b;
	int	c;

	a = (*s)->nbr;
	b = (*s)->next->nbr;
	c = (*s)->next->next->nbr;
	if (a < b)
	{
		rra(s, true);
		if (a < c)
			sa(s);
	}
	else
	{
		if (a > c)
		{
			ra(s, true);
			if (b > c)
				sa(s);
		}
		else
			sa(s);
	}
}

void	sort_two(t_stack **s)
{
	sa(s);
}

void	sort(t_stack **a, t_stack **b)
{
	if (stack_length(*a) == 2)
		sort_two(a);
	else if (stack_length(*a) == 3)
		sort_three(a);
	else
		sort_n(a, b);
}
