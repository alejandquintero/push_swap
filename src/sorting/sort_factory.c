/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_factory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:32:55 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/13 17:07:51 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	if (stack_length(*a) == 2)
		sort_two(a);
	else if (stack_length(*a) == 3)
		sort_three(a);
	else
		sort_n(a, b);
}
