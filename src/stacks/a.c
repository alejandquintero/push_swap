/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:49:56 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/06 16:43:11 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sa(t_stack **a)
{
	ft_printf("sa\n");
	swap(a);
	save_index_node(a);
}

void	ra(t_stack **a)
{
	ft_printf("ra\n");
	rotate(a);
	save_index_node(a);
}

void	rra(t_stack **a)
{
	ft_printf("rra\n");
	reverse(a);
	save_index_node(a);
}

void	pa(t_stack **b, t_stack **a)
{
	ft_printf("pa\n");
	push(b, a);
	save_index_node(a);
	save_index_node(b);
}
