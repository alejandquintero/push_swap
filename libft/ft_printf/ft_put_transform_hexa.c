/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_transform_hexa.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:07:17 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/23 19:52:35 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_puthexa_putchar(unsigned long long int n, int *len, int ascii)
{
	if (n > 9)
	{
		if (ft_putchar(n + ascii, len) == -1)
			return (-1);
	}
	else
	{
		if (ft_putchar(n + '0', len) == -1)
			return (-1);
	}
	return (0);
}

int	ft_put_transform_hexa(unsigned long long int n, int *len, int ascii)
{
	if (n > 15)
	{
		if (ft_put_transform_hexa(n / 16, len, ascii) == -1)
			return (-1);
		if (n % 16 > 9)
		{
			if (ft_putchar(n % 16 + ascii, len) == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar(n % 16 + '0', len) == -1)
				return (-1);
		}
	}
	else
	{
		if (ft_puthexa_putchar(n, len, ascii) == -1)
			return (-1);
	}
	return (0);
}
