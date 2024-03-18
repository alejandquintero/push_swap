/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:10:31 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/18 21:13:17 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void print_stacks(t_stack *a, t_stack *b)
{
	t_stack *aux_a;
	t_stack *aux_b;
	aux_a = a;
	aux_b = b;
	while (aux_a != NULL && aux_b != NULL)
	{
		printf("%d\t%d\n", aux_a->number, aux_b->number);
		aux_a = aux_a->next;
		aux_b = aux_b->next;
	}
}