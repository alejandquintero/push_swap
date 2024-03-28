/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 21:59:31 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/28 22:38:37 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_three(t_stack **s)
{
	if (!is_sorted(*s))
	{
		if ((*s)->nbr < (*s)->next->nbr)
		{
			rra(s);
			if ((*s)->nbr < (*s)->next->next->nbr)
				sa(s);
		}
		else
		{
			if ((*s)->nbr > (*s)->next->next->nbr)
			{
				ra(s);
				if ((*s)->next->nbr > (*s)->next->next->nbr)
					sa(s);
			}
			else
				sa(s);
		}
	}
}
