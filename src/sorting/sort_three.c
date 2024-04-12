/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 21:59:31 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/12 23:27:11 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

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
