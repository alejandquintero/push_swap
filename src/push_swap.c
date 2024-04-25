/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:05:38 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/25 23:14:54 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void leaks(void)
{
	system("leaks -q push_swap");
}

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

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	**nbrs;
	t_stack	*a;
	t_stack	*b;
	long	nbr;
	
	// atexit(leaks);
	i = 1;
	a = NULL;
	b = NULL;
	nbrs = NULL;
	if (argc < 2)
		error(nbrs, a);
	if (ft_strlen(argv[i]) < 1)
		error(nbrs, a);
	while (argv[i])
	{
		nbrs = ft_split(argv[i], ' ');
		j = 0;
		while (nbrs[j] != NULL)
		{	
			if (!valid_syntax(nbrs[j]))
				error(nbrs, a);
			nbr = ft_stol(nbrs[j]);
			if (nbr < INT_MIN || nbr > INT_MAX)
				error(nbrs, a);
			if (!is_nbr_unique_in_stack(a, nbr))
				error(nbrs, a);
			stack_add_back(&a, stack_new((int)nbr, i + j - 1));
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
