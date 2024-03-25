/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:41:19 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/25 22:05:20 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	swap(t_stack **s)
{
	t_stack *aux;

	if (*s != NULL && (*s)->next != NULL)
	{
		aux = *s;
		*s = (*s)->next;
		aux->next = (*s)->next;
		(*s)->next = aux;
	}
}

void	rotate(t_stack **s)
{
	t_stack *aux;

	if (*s != NULL)
	{
		aux = *s;
		*s = (*s)->next;
		aux->next = NULL;
		stack_add_back(s, aux);
	}
}

void	reverse(t_stack **s)
{
	t_stack *aux;
	t_stack *last;
	(void)last;

	if (*s != NULL && (*s)->next != NULL)
	{
		last = stack_last(*s);
		aux = *s;
		while (aux->next->next != NULL)
			aux = aux->next;
		aux->next = NULL;
		stack_add_front(s, last);
	}
}

void	push(t_stack **from, t_stack **to)
{
	t_stack *head_from;
	t_stack *head_to;

	if (*from != NULL)
	{
		head_to = *to;
		head_from = *from;
		*from = (*from)->next;
		if (head_to == NULL)
		{
			head_from->next = NULL;
			*to = head_from;
		}
		else
		{
			head_from->next = *to;
			*to = head_from;
		}
	}
}
