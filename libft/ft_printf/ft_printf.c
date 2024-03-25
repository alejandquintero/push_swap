/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:55:00 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/23 19:44:53 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_print_factory(char const *str, va_list ptr, int *len)
{
	if (*str == 'd' || *str == 'i')
		return (ft_putnbr(va_arg(ptr, int), len));
	else if (*str == 'p')
		return (ft_putptr(va_arg(ptr, unsigned long long int), len));
	else if (*str == 'u')
		return (ft_putunsigned(va_arg(ptr, unsigned int), len));
	else if (*str == 'X')
		return (ft_puthexa(va_arg(ptr, unsigned int), len, 55));
	else if (*str == 'x')
		return (ft_puthexa(va_arg(ptr, unsigned int), len, 87));
	else if (*str == 'c')
		return (ft_putchar(va_arg(ptr, int), len));
	else if (*str == 's')
		return (ft_putstr(va_arg(ptr, char *), len));
	else if (*str == '%')
		return (ft_putchar('%', len));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list	ptr;
	int		len;

	len = 0;
	va_start(ptr, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (ft_print_factory(str, ptr, &len) == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar(*str, &len) == -1)
				return (-1);
		}
		str++;
	}
	va_end(ptr);
	return (len);
}
