/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_limit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 15:45:54 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/26 14:49:42 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * This function is kind of an atoi except you have to ensure you are sending
 * a string of only digits to it
 * It will return the string converted into integers, as long as it doesn't
 * reach the limit. If it does, it will return the limit.
*/

int	atoi_limit(const char *str, int limit)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (nb < limit)
			nb = (nb * 10) + (str[i] - '0');
		else
			return (limit);
		i++;
	}
	if (nb > limit)
		return (limit);
	return (nb);
}
