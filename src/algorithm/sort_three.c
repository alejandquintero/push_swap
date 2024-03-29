/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 21:59:31 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/23 17:42:43 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_three(t_stack **s, char stack)
{
	int	a;
	int	b;
	int	c;

	a = (*s)->number;
	b = (*s)->next->number;
	c = (*s)->next->next->number;
	if (!is_sorted(*s))
	{
		if (a < b)
		{
			exec(s, "reverse", stack);
			if (a < c)
				exec(s, "swap", stack);
		}
		else
		{
			if (a > c)
			{
				exec(s, "rotate", stack);
				if (b > c)
					exec(s, "swap", stack);
			}
			else
				exec(s, "swap", stack);
		}
	}
}
