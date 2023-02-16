/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:03:35 by sylducam          #+#    #+#             */
/*   Updated: 2023/02/16 16:21:14 by sylducam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pf_atoi(char **str)
{
	int	total;
	int	sign;

	total = 0;
	sign = 1;
	while ((*(*str) >= 9 && *(*str) <= 13) || *(*str) == 32 || *(*str) == ','
		|| ft_isalpha(*(*str)))
		(*str)++;
	if (*(*str) == '+' || *(*str) == '-')
	{
		if (*(*str) == '-')
			sign *= -1;
		(*str)++;
	}
	while (ft_isdigit(*(*str)))
	{
		total = (total * 10) + *(*str) - '0';
		(*str)++;
	}
	return (total * sign);
}
