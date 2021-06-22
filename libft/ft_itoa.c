/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <pmillet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:33:46 by pmillet           #+#    #+#             */
/*   Updated: 2021/03/20 09:12:17 by pmillet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft.h"

static int	char_count(int n)
{
	int	c;

	if (n < 0)
		n = -n;
	c = 1;
	while (n > 9)
	{
		c++;
		n = n / 10;
	}
	return (c);
}

static char	*fill_tab(char *res, int i, int n, int neg)
{
	while (n >= 10)
	{
		res[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	res[i] = n + '0';
	if (neg == 1)
	{
		i--;
		res[i] = '-';
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		neg;
	int		c;

	res = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	c = char_count(n);
	i = c;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	res = wrmalloc((sizeof(char) * (c + 1 + neg)));
	if (res == NULL)
		return (NULL);
	i += neg;
	res[i] = '\0';
	i--;
	return (fill_tab(res, i, n, neg));
}
