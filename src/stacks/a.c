/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:49:56 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/22 23:28:11 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sa(t_stack **a)
{
	printf("sa\n");
	swap(a);
}

void	ra(t_stack **a)
{
	printf("ra\n");
	rotate(a);	
}

void	rra(t_stack **a)
{
	printf("rra\n");
	reverse(a);	
}

void	pa(t_stack **b, t_stack **a)
{
	printf("pa\n");
	push(b, a);	
}