/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:49:56 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/21 23:05:19 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sa(t_stack **a)
{
	swap(a);
}

void	ra(t_stack **a)
{
	rotate(a);	
}

void	rra(t_stack **a)
{
	reverse(a);	
}

void	pa(t_stack **b, t_stack **a)
{
	push(b, a);	
}