/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 00:02:38 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/23 19:52:35 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_putstr(char *s, int *len)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)", len));
	else
	{
		while (s[i] != '\0')
		{
			if (ft_putchar(s[i], len) == -1)
				return (-1);
			i++;
		}
	}
	return (0);
}
