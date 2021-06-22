/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:17:16 by sylducam          #+#    #+#             */
/*   Updated: 2021/06/22 16:17:19 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_celling_floor(t_setup *setup)
{
	int	i;

	i = 0;
	if (setup->game.drawstart > 0)
	{
		while (i < setup->game.drawstart)
		{
			setup->game.buf[i][setup->x] = setup->game.c_color.color;
			i++;
		}
	}
	i = setup->game.drawend;
	while (i < setup->height - 1)
	{
		setup->game.buf[i][setup->x] = setup->game.f_color.color;
		i++;
	}
}
