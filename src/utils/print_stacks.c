/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:10:31 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/28 21:41:38 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	while (a != NULL || b != NULL)
	{
		if (a != NULL)
		{
			ft_printf("%d\t", a->nbr);
			a = a->next;
		}
		else
			ft_printf("null\t");
		if (b != NULL)
		{
			ft_printf("%d\n", b->nbr);
			b = b->next;
		}
		else
			ft_printf("null\t\n");
	}
	ft_printf("\n");
}

void	print_sorted_stack(t_stack *a)
{
	while (a->next != NULL)
	{
		ft_printf("%d ", a->nbr);
		a = a->next;
	}
	ft_printf("%d", a->nbr);
}
