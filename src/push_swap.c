/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:05:38 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/22 22:29:32 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

bool	valid_syntax(char *nbr)
{
	if (*nbr == '-')
		nbr++;
	while (*nbr)
	{
		if (*nbr < '0' || *nbr > '9')
			return (false);
		nbr++;
	}
	return (true);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	**nbrs;
	t_stack	*a;
	t_stack	*b;

	i = 1;
	a = NULL;
	b = NULL;
	if (argc < 2)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	while (argv[i])
	{
		nbrs = ft_split(argv[i], ' ');
		j = 0;
		while (nbrs[j] != NULL)
		{	
			ft_printf("%s\n",nbrs[j]);
			if (!valid_syntax(nbrs[j]))
			{
				free_nbrs(nbrs);
				stack_clear(&a);
				stack_clear(&b);
				write(STDERR_FILENO, "Error\n", 6);
				return (1);
			}
			// TODO Verificar si es menor o igual que el INT_MIN o menor o igual que INT_MAX
			// TODO Verificar si el numero ya está repetido
			stack_add_back(&a, stack_new(ft_atoi(nbrs[j]), i + j - 1));
			j++;
		}
		free_nbrs(nbrs);
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
