/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:50:35 by aquinter          #+#    #+#             */
/*   Updated: 2024/04/27 17:25:03 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	stack_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*aux;

	if (new != NULL)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			aux = *lst;
			while (aux->next != NULL)
				aux = aux->next;
			aux->next = new;
		}
	}
}

void	stack_add_front(t_stack **lst, t_stack *new)
{
	if (new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

int	stack_length(t_stack *s)
{
	int	c;

	c = 0;
	if (s != NULL)
	{
		while (s != NULL)
		{
			c++;
			s = s->next;
		}
	}
	return (c);
}

t_stack	*stack_last(t_stack *lst)
{
	t_stack	*current;

	current = lst;
	while (current != NULL && current->next != NULL)
		current = current->next;
	return (current);
}

t_stack	*stack_new(int number)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	(*new_node).nbr = number;
	(*new_node).index = 0;
	(*new_node).target = NULL;
	(*new_node).next = NULL;
	return (new_node);
}
