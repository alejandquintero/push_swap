/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:15:21 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/28 21:41:38 by aquinter         ###   ########.fr       */
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
