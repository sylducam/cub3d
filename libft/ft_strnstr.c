/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <pmillet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 08:48:04 by pmillet           #+#    #+#             */
/*   Updated: 2021/03/20 10:15:35 by pmillet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*search_needle(const char *haystack, const char *needle, \
size_t len, size_t i)
{
	int		res;
	size_t	j;
	int		si;

	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i] == needle[0] && i < len)
		{
			res = i;
			j = 1;
			si = i;
			i++;
			while (haystack[i] == needle[j] && needle[j] != '\0' && i < len)
			{
				j++;
				i++;
			}
			if (j == ft_strlen(needle))
				return (&haystack[res]);
			else
				i = si + 1;
		}
		i++;
	}
	return ((const char *) NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, \
size_t len)
{
	size_t	i;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	if ((int)len == 0)
		return (NULL);
	return ((char *)search_needle(&haystack[i], needle, len, i));
}
