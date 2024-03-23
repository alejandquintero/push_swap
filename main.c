/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:23:03 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/23 16:05:59 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "inc/push_swap.h"

int	main(int argc, char *argv[])
{
	(void)argc;

	int i = 1;
	t_stack *a;
	t_stack *b;
	a = NULL;
	b = NULL;
	while (argv[i])
	{
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	print_stacks(a, b);

	sort_three(&a);

	print_stacks(a, b);

	// printf("sa\n");
	// sa(&a);
	// print_stacks(a, b);
	// printf("ra\n");
	// ra(&a);
	// print_stacks(a, b);
	// printf("rra\n");
	// rra(&a);
	// print_stacks(a, b);


	// printf("pb\n");
	// pb(&a, &b);
	// print_stacks(a, b);
	// printf("pb\n");
	// pb(&a, &b);
	// print_stacks(a, b);

	// printf("pb\n");
	// pb(&a, &b);
	// print_stacks(a, b);


	// printf("pb\n");
	// pb(&a, &b);
	// print_stacks(a, b);

	// printf("pa\n");
	// pa(&b, &a);
	// print_stacks(a, b);
	// printf("pa\n");
	// pa(&b, &a);
	// print_stacks(a, b);


	// printf("pa\n");
	// pa(&b, &a);
	// print_stacks(a, b);
	

	// printf("pb\n");
	// pb(&a, &b);
	// print_stacks(a, b);
	// printf("pb\n");
	// pb(&a, &b);
	// print_stacks(a, b);
	// printf("pb\n");
	// pb(&a, &b);
	// print_stacks(a, b);
	// printf("ss\n");
	// ss(&a, &b);
	// print_stacks(a, b);

	// printf("rr\n");
	// rr(&a, &b);
	// print_stacks(a, b);

	// printf("rrr\n");
	// rrr(&a, &b);
	// print_stacks(a, b);
	
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}