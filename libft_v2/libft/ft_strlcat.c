/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:32:55 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/23 19:20:56 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	i;

	dstlen = ft_strlen(dst);
	if (dstsize > dstlen)
	{
		i = 0;
		while ((dstlen + i) < (dstsize - 1) && src[i] != '\0')
		{
			dst[dstlen + i] = src[i];
			i++;
		}
		dst[i + dstlen] = '\0';
		return (dstlen + ft_strlen(src));
	}
	return (ft_strlen(src) + dstsize);
}
