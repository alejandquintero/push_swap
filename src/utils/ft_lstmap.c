/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:28:22 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/16 22:40:30 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*aux;
	t_list	*node;
	int	number;

	(void)f;
	(void)del;
	(void)number;
	number =1;
	head = NULL;
	if (lst != NULL)
	{
		aux = lst;
		while (aux != NULL)
		{
			node = ft_lstnew(number);
			if (!node)
			{
				// del(str);
				ft_lstclear(&head, del);
				return (NULL);
			}
			ft_lstadd_back(&head, node);
			aux = aux->next;
		}
	}
	return (head);
}
