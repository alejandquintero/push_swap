/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:31:43 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/16 22:37:46 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	(void)del;
	if (lst != NULL)
	{
		free(lst);
	}
}
