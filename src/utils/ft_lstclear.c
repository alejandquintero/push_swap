/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:11:16 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/16 21:40:23 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;
	t_list	*next;

	if (*lst != NULL)
	{
		aux = *lst;
		while (aux != NULL)
		{
			next = aux->next;
			ft_lstdelone(aux, del);
			aux = next;
		}
		*lst = NULL;
	}
}
