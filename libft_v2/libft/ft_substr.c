/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquinter <aquinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:33:06 by aquinter          #+#    #+#             */
/*   Updated: 2024/03/23 19:20:56 by aquinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		s2 = malloc(1 * sizeof(char));
		if (!s2)
			return (NULL);
		s2[0] = '\0';
		return (s2);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	s2 = malloc((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s + start, len + 1);
	return (s2);
}
