/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:50:28 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/12 23:25:14 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sb(t_stack **b)
{
	ft_printf("sb\n");
	swap(b);
	save_index_node(b);
}

void	rb(t_stack **b, bool print)
{
	if (print)
		ft_printf("rb\n");
	rotate(b);
	save_index_node(b);
}

void	rrb(t_stack **b, bool print)
{
	if (print)
		ft_printf("rrb\n");
	reverse(b);
	save_index_node(b);
}

void	pb(t_stack **a, t_stack **b)
{
	ft_printf("pb\n");
	push(a, b);
	save_index_node(a);
	save_index_node(b);
}
