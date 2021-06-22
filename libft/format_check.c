/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 12:57:13 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/31 14:32:40 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	format_check(char *file, char *format)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!file || !format || !*file || !*format)
		return (-1);
	while (file[i])
		i++;
	i -= ft_strlen(format);
	while (file[i] && format[j])
	{
		if (file[i] != format[j])
			return (-1);
		i++;
		j++;
	}
	return (0);
}
