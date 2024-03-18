/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:23:03 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/18 23:23:45 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "inc/push_swap.h"

int	main(int argc, char *argv[])	
{
	(void)argc;

	int i = 2;
	t_stack *a;
	t_stack *b;
	a = ft_lstnew(ft_atoi(argv[1]));
	b = ft_lstnew(0);
	while (argv[i])
	{
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i])));
		ft_lstadd_back(&b, ft_lstnew(0));
		i++;
	}
	print_stacks(a, b);
	printf("sa\n");
	sa(&a);
	print_stacks(a, b);
	printf("ra\n");
	ra(&a);
	print_stacks(a, b);
	printf("rra\n");
	rra(&a);
	print_stacks(a, b);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}