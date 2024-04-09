/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:05:38 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/08 09:13:48 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "stdio.h"

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
	print_stacks(a, b);

	if (!is_sorted(a))
		sort(&a, &b);
	else
		ft_printf("Stack is sorted!\n");

	print_stacks(a, b);



	// t_stack *aux = b;
	// while (aux)
	// {
	// 	t_stack *target = get_bigger_target_node(aux->nbr, a);
	// 	ft_printf("Big Target node %d -> ", aux->nbr);
	// 	ft_printf("%d\n", target->nbr);
	// 	aux = aux->next;
	// }

	print_sorted_stack(a);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
