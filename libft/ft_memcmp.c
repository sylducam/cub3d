/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <pmillet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:46:21 by pmillet           #+#    #+#             */
/*   Updated: 2021/03/20 09:12:41 by pmillet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*casts1;
	unsigned char	*casts2;

	casts1 = (unsigned char *)s1;
	casts2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (casts1[i] == casts2[i])
			i++;
		else
			return (casts1[i] - casts2[i]);
	}
	return (0);
}
