/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:58:47 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/11 13:22:15 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*change_char(char *str, char in, char out)
{
	char	*changed_str;
	int		i;

	i = 0;
	if (!str || !*str || !in || !out)
		return (str);
	changed_str = ft_strdup(str);
	if (changed_str == NULL)
		return (str);
	while (changed_str[i])
	{
		if (changed_str[i] == out)
			changed_str[i] = in;
		i++;
	}
	wrfree(str);
	return (changed_str);
}
