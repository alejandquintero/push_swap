/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:50:28 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/21 23:07:03 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sb(t_stack **b)
{
	swap(b);
}

void	rb(t_stack **b)
{
	rotate(b);	
}

void	rrb(t_stack **b)
{
	reverse(b);	
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);	
}