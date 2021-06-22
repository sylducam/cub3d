/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <pmillet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:49:23 by pmillet           #+#    #+#             */
/*   Updated: 2021/03/20 09:24:44 by pmillet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	if (src == NULL || dest == NULL || dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	if (dstsize < 1)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (dest[i])
		dest[i] = '\0';
	return (ft_strlen(src));
}
