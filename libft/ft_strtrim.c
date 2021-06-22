/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <pmillet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:27:07 by pmillet           #+#    #+#             */
/*   Updated: 2021/03/20 10:16:18 by pmillet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_set_beg(char const *s1, char const *set)
{
	int		i;
	size_t	j;
	int		tb;

	i = 0;
	j = 0;
	tb = 0;
	while (s1 && set[j])
	{
		if (s1[i] == set[j])
		{
			tb++;
			i++;
			j = 0;
		}
		else if (j < ft_strlen(set) - 1)
			j++;
		else
			return (tb);
	}
	return (0);
}

static int	is_set_end(char const *s1, char const *set, int i)
{
	size_t	j;
	int		te;

	j = 0;
	te = 0;
	while (i >= 0 && set[j])
	{
		if (s1[i] == set[j])
		{
			te++;
			i--;
			j = 0;
		}
		else if (j < ft_strlen(set) - 1)
			j++;
		else
			return (te);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		te;
	size_t	j;
	size_t	max;
	char	*res;

	if (s1 == NULL)
	{
		res = NULL;
		return (res);
	}
	j = is_set_beg(s1, set);
	te = is_set_end(s1, set, (ft_strlen(s1) - 1));
	max = ft_strlen(s1) - te;
	i = 0;
	res = "\0";
	res = wrmalloc((sizeof(char)) * (max - j + 1));
	if (res == NULL)
		return (NULL);
	while (j < max)
	{
		res[i++] = s1[j++];
	}
	res[i] = '\0';
	return (res);
}
