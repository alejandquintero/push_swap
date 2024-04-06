/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simultaneous.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:51:28 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/06 16:44:40 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ss(t_stack **a, t_stack **b)
{
	ft_printf("ss\n");
	sa(a);
	sb(b);
	save_index_node(a);
	save_index_node(b);
}

void	rr(t_stack **a, t_stack **b)
{
	ft_printf("rr\n");
	ra(a);
	rb(b);
	save_index_node(a);
	save_index_node(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	ft_printf("rrr\n");
	rra(a);
	rrb(b);
	save_index_node(a);
	save_index_node(b);
}
