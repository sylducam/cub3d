/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmillet <pmillet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:31:16 by pmillet           #+#    #+#             */
/*   Updated: 2021/03/20 10:17:12 by pmillet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include "libft.h"

int	ft_toupper(int c)
{
	if (!ft_isalpha(c))
		return (c);
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
