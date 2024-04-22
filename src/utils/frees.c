/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:53:47 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/22 21:54:28 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	free_nbrs(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	while (i > 0)
	{
		free(str[i - 1]);
		i--;
	}
	free(str);		
}

void	del_one(t_stack *lst)
{
	if (lst != NULL)
		free(lst);
}

void	stack_clear(t_stack **lst)
{
	t_stack	*aux;
	t_stack	*next;

	if (*lst != NULL)
	{
		aux = *lst;
		while (aux != NULL)
		{
			next = aux->next;
			del_one(aux);
			aux = next;
		}
		*lst = NULL;
	}
}
