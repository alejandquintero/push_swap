/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:05:38 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/30 21:19:08 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long	ft_stol(const char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	num = 0;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		num = (num * 10) + (str[i] - 48);
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

void	build_stack(char *argv[], t_stack **a)
{
	char	**nbrs;
	long	nbr;
	int		i;

	nbrs = NULL;
	if (ft_strlen(*argv) < 1)
		error(nbrs, *a);
	while (*argv != NULL)
	{
		nbrs = ft_split(*argv, ' ');
		i = -1;
		while (nbrs[++i] != NULL)
		{
			if (!valid_syntax(nbrs[i]))
				error(nbrs, *a);
			nbr = ft_stol(nbrs[i]);
			if (nbr < INT_MIN || nbr > INT_MAX)
				error(nbrs, *a);
			if (!is_nbr_unique_in_stack(*a, nbr))
				error(nbrs, *a);
			stack_add_back(a, stack_new((int)nbr));
		}
		free_nbrs(nbrs);
		argv++;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < MIN_ARGUMENTS)
		error(NULL, a);
	build_stack(++argv, &a);
	if (!is_sorted(a))
		sort(&a, &b);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
