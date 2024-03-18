/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:41:19 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/18 23:23:18 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	s(t_stack **s)
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

void	r(t_stack **s)
{
	t_stack *aux;

	aux = *s;
	*s = (*s)->next;
	aux->next = NULL;
	ft_lstadd_back(s, aux);
}

void	rr(t_stack **s)
{
	t_stack *aux;
	t_stack *last;

	last = ft_lstlast(*s);
	aux = *s;
	while (aux->next->next != NULL)
		aux = aux->next;
	aux->next = NULL;	
	ft_lstadd_front(s, last);
}