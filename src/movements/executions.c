/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:24:43 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/23 17:36:58 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	exec(t_stack **s, char *movement, char stack)
{
	if (movement == "swap")
	{
		printf("s%c\n", stack);
		swap(s);	
	}
	else if (movement == "rotate")
	{
		printf("r%c\n", stack);
		rotate(s);
	}
	else if (movement == "reverse")
	{
		printf("rr%c\n", stack);
		reverse(s);
	}
}
