/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:05:38 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/06 01:11:38 by aquinter         ###   ########.fr       */
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
		stack_add_back(&a, stack_new(ft_atoi(argv[i])));
		i++;
	}
	// t_stack	*c = get_min_node(a);
	// ft_printf("min: %d\n", c->nbr);
	// t_stack	*d = get_max_node(a);
	// ft_printf("max: %d\n", d->nbr);
	
	pb(&a, &b);	
	pb(&a, &b);	
	pb(&a, &b);
	rrb(&b);
	pb(&a, &b);
	rb(&b);
	pb(&a, &b);
	sort_three(&a);
	pa(&b, &a);
	rra(&a);
	rra(&a);
	pa(&b, &a);
	pa(&b, &a);
	pa(&b, &a);
	pa(&b, &a);
	rra(&a);
	
	print_stacks(a, b);

	// t_stack *aux = a;
	// while (aux)
	// {
	// 	t_stack *target = get_smaller_target_node(aux->nbr, b);
	// 	ft_printf("Small Target node %d -> ", aux->nbr);
	// 	ft_printf("%d\n", target->nbr);
	// 	aux = aux->next;
	// }

	t_stack *aux = b;
	while (aux)
	{
		t_stack *target = get_bigger_target_node(aux->nbr, a);
		ft_printf("Big Target node %d -> ", aux->nbr);
		ft_printf("%d\n", target->nbr);
		aux = aux->next;
	}

	
	// sort_three(&a);
	// print_sorted_stack(a);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
