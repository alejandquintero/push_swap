/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:32:53 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/16 21:40:23 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

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
