/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:10:31 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/22 23:29:54 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void print_stacks(t_stack *a, t_stack *b)
{
	while (a != NULL || b != NULL)
	{
		if (a != NULL){
			printf("%d\t", a->number);
			a = a->next;			
		}
		else
			printf("null\t");
		if (b != NULL){
			printf("%d\n", b->number);
			b = b->next;
		}
		else
			printf("null\t\n");
	}
	printf("\n");
}