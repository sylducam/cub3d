/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <pmillet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:26:55 by pmillet           #+#    #+#             */
/*   Updated: 2021/03/20 09:13:17 by pmillet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static void	*reverse_move(unsigned char *castdest, unsigned char *castsrc, \
size_t n, size_t i)
{
	i = n;
	while (i > 0)
	{
		i--;
		castdest[i] = castsrc[i];
	}
	return (castdest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*castsrc;
	unsigned char	*castdest;

	castsrc = (unsigned char *)src;
	castdest = (unsigned char *)dest;
	i = 0;
	if (castdest == NULL && castsrc == NULL)
		return (NULL);
	if (castdest < castsrc)
	{
		while (i < n)
		{
			castdest[i] = castsrc[i];
			i++;
		}
	}
	else
		return (reverse_move(castdest, castsrc, n, i));
	return (dest);
}
