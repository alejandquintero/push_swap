/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:35:12 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/18 20:54:29 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_lstiter(t_stack *lst, void (*f)(void *))
{
	t_stack	*aux;

	(void)f;
	if (lst != NULL)
	{
		aux = lst;
		while (aux != NULL)
		{
			aux = aux->next;
		}
	}
}
