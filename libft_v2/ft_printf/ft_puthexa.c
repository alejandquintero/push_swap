/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 23:51:34 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/23 19:52:35 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_puthexa(unsigned int n, int *len, int ascii)
{
	return (ft_put_transform_hexa((unsigned long long int)n, len, ascii));
}
