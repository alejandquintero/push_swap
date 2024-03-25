/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:24:43 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/25 22:15:38 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	exec(t_stack **s, char *movement, char stack)
{
	if (ft_strncmp(movement, "swap", 4) == 0)
	{
		ft_printf("s%c\n", stack);
		swap(s);	
	}
	else if (ft_strncmp(movement, "rotate", 6) == 0)
	{
		ft_printf("r%c\n", stack);
		rotate(s);
	}
	else if (ft_strncmp(movement, "reverse", 7) == 0)
	{
		ft_printf("rr%c\n", stack);
		reverse(s);
	}
}
