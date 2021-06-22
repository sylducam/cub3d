/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_char_p2p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:49:38 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/10 16:49:41 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	free_char_p2p(char **tab)
{
	int	i;

	i = 0;
	if (!tab || !*tab)
		return (-1);
	while (tab[i])
	{
		wrfree(tab[i]);
		tab[i] = NULL;
		i++;
	}
	wrfree(tab);
	tab = NULL;
	return (0);
}
