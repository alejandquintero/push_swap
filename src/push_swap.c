/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:05:38 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/23 17:18:54 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
	sort_three(&a);
	print_sorted_stack(a);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}