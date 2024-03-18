/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:28:22 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/18 20:57:39 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack	*ft_lstmap(t_stack *lst, void *(*f)(void *), void (*del)(void *))
{
	t_stack	*head;
	t_stack	*aux;
	t_stack	*node;
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
				ft_lstclear(&head);
				return (NULL);
			}
			ft_lstadd_back(&head, node);
			aux = aux->next;
		}
	}
	return (head);
}
