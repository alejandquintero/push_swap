/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:50:28 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/25 22:26:23 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sb(t_stack **b)
{
	ft_printf("sb\n");
	swap(b);
}

void	rb(t_stack **b)
{
	ft_printf("rb\n");
	rotate(b);
}

void	rrb(t_stack **b)
{
	ft_printf("rrb\n");
	reverse(b);
}

void	pb(t_stack **a, t_stack **b)
{
	ft_printf("pb\n");
	push(a, b);
}
