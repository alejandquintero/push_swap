/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:44:33 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/18 20:54:29 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}
