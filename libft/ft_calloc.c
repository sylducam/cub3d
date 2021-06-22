/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <pmillet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:39:00 by pmillet           #+#    #+#             */
/*   Updated: 2021/03/20 09:08:30 by pmillet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void		*ptr;
	size_t		i;

	ptr = wrmalloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	i = 0;
	while (i < (count * size))
	{
		if (*(unsigned char *)(ptr + i) != 0)
		{
			return (NULL);
		}
		i++;
	}
	return (ptr);
}
