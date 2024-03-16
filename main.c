/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:23:03 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/16 22:36:38 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "inc/push_swap.h"

void	free_mem(void *content){
	free(content);
}

int	main(int argc, char *argv[])	
{
	(void)argc;
	// int	sum;
		

	int i = 2;
	t_list *stack;
	stack = ft_lstnew(ft_atoi(argv[1]));
	while (argv[i])
	{
		ft_lstadd_back(&stack, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	t_list *aux;
	aux = stack;
	while (aux != NULL)
	{
		printf("%d\n", aux->number);
		aux = aux->next;
	}
	ft_lstclear(&stack, free_mem);
	// sum = ft_atoi(argv[1]) + ft_atoi(argv[2]);
	// system("leaks -q push_swap");
	// printf("%d", sum);
	return (0);
}