/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:05:38 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/25 22:16:56 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_stol(const char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	num = 0;
	sign = 1;	
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - 48);
		if (num < INT_MIN|| num > INT_MAX)
		{
			write(STDERR_FILENO, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (num * sign);
}

bool	is_nbr_unique_in_stack(t_stack *s, int nbr)
{
	while (s != NULL)
	{
		if (s->nbr == nbr)
			return (false);
		s = s->next;
	}
	return (true);
}

bool	valid_syntax(char *nbr)
{
	if (*nbr == '-')
		nbr++;
	if (*nbr < '0' || *nbr > '9')
		return (false);
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
	if (ft_strlen(argv[i]) < 1)
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
			if (!valid_syntax(nbrs[j]))
			{
				free_nbrs(nbrs);
				stack_clear(&a);
				stack_clear(&b);
				write(STDERR_FILENO, "Error\n", 6);
				return (1);
			}
			int	nbr = (int)ft_stol(nbrs[j]);
			if (!is_nbr_unique_in_stack(a, nbr))
			{
				free_nbrs(nbrs);
				stack_clear(&a);
				stack_clear(&b);
				write(STDERR_FILENO, "Error\n", 6);
				return (1);
			}
			stack_add_back(&a, stack_new(nbr, i + j - 1));
			j++;
		}
		free_nbrs(nbrs);
		i++;
	}
	if (!is_sorted(a))
		sort(&a, &b);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
