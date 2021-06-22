/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <pmillet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:52:18 by pmillet           #+#    #+#             */
/*   Updated: 2021/03/20 10:17:10 by pmillet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include "libft.h"

int	ft_tolower(int c)
{
	if (!ft_isalpha(c))
		return (c);
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
