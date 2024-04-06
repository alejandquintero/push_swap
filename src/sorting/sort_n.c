/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:44:23 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/06 18:22:05 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_n(t_stack **a, t_stack **b)
{
	int len;
	// t_stack *min_node;

	len = stack_len(*a);
	pb(a, b);
	if (len != 4)
		pb(a, b);
	while (stack_len(*a) != 3)
	{	
		set_targets_node(a, *b);
		push_cheapest_node(a, b);
		// calculate target smaller nodes and pb
		break;
	}

	// t_stack *aux = *a;
	// while (aux)
	// {
	// 	ft_printf("Small Target node %d (%d) -> %d (%d) \n", (aux)->nbr, aux->index, (aux)->target->nbr, aux->target->index );
	// 	aux = aux->next;
	// }
	

	// sort_three(a);
	// while (b)
	// {
	//  	break;
	// 	// calculate target bigger nodes and pa
	// }
 	// min_node = get_min_node(*a);
	// len = stack_len(*a);
	// while (min_node->index != 0)	
	// {
	// 	if (min_node->index < len / 2)
	// 		ra(a);
	// 	else
	// 		rra(a);
	//  	min_node = get_min_node(*a);
	// }
}
