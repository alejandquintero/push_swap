/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:05:38 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/20 14:50:06 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	(void)argc;
	i = 1;
	a = NULL;
	b = NULL;
	while (argv[i])
	{
		stack_add_back(&a, stack_new(ft_atoi(argv[i]), i - 1));
		i++;
	}
	if (!is_sorted(a))
	{
		sort(&a, &b);
		// print_sorted_stack(a);
	}
	// else
	// 	ft_printf("Stack is sorted!\n");
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
