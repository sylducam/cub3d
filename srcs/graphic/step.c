/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:18:12 by sylducam          #+#    #+#             */
/*   Updated: 2021/06/22 16:18:15 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calc_step_x(t_setup *setup)
{
	if (setup->game.raydir_x < 0)
	{
		setup->game.step_x = -1;
		setup->game.sidedist_x = (setup->game.pos_x - setup->game.map_x) \
		* setup->game.deltadist_x;
	}
	else
	{
		setup->game.step_x = 1;
		setup->game.sidedist_x = (setup->game.map_x + 1.0 - setup->game.pos_x) \
		* setup->game.deltadist_x;
	}
}

void	calc_step_y(t_setup *setup)
{
	if (setup->game.raydir_y < 0)
	{
		setup->game.step_y = -1;
		setup->game.sidedist_y = (setup->game.pos_y - \
		setup->game.map_y) * setup->game.deltadist_y;
	}
	else
	{
		setup->game.step_y = 1;
		setup->game.sidedist_y = (setup->game.map_y + 1.0 \
		- setup->game.pos_y) * setup->game.deltadist_y;
	}
}
