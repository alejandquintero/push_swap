/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:32:53 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/18 20:54:29 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
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
