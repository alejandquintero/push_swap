/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:11:16 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/18 20:56:15 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*aux;
	t_stack	*next;

	if (*lst != NULL)
	{
		aux = *lst;
		while (aux != NULL)
		{
			next = aux->next;
			ft_lstdelone(aux);
			aux = next;
		}
		*lst = NULL;
	}
}
