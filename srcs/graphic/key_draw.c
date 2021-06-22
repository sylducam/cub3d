/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:17:48 by sylducam          #+#    #+#             */
/*   Updated: 2021/06/22 16:17:55 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_rotate_left(t_setup *setup)
{
	double	olddir_x;
	double	oldplane_x;

	if (setup->key.rotate_left == 1)
	{
		olddir_x = setup->game.dir_x;
		setup->game.dir_x = setup->game.dir_x * cos(-setup->game.rotspeed) \
		- setup->game.dir_y * sin(-setup->game.rotspeed);
		setup->game.dir_y = olddir_x * sin(-setup->game.rotspeed) \
		+ setup->game.dir_y * cos(-setup->game.rotspeed);
		oldplane_x = setup->game.plane_x;
		setup->game.plane_x = setup->game.plane_x * cos(-setup->game.rotspeed) \
		- setup->game.plane_y * sin(-setup->game.rotspeed);
		setup->game.plane_y = oldplane_x * sin(-setup->game.rotspeed) \
		+ setup->game.plane_y * cos(-setup->game.rotspeed);
	}
}

void	draw_rotate_right(t_setup *setup)
{
	double	olddir_x;
	double	oldplane_x;

	if (setup->key.rotate_right == 1)
	{
		olddir_x = setup->game.dir_x;
		setup->game.dir_x = setup->game.dir_x * cos(setup->game.rotspeed) \
		- setup->game.dir_y * sin(setup->game.rotspeed);
		setup->game.dir_y = olddir_x * sin(setup->game.rotspeed) \
		+ setup->game.dir_y * cos(setup->game.rotspeed);
		oldplane_x = setup->game.plane_x;
		setup->game.plane_x = setup->game.plane_x * cos(setup->game.rotspeed) \
		 - setup->game.plane_y * sin(setup->game.rotspeed);
		setup->game.plane_y = oldplane_x * sin(setup->game.rotspeed) \
		+ setup->game.plane_y * cos(setup->game.rotspeed);
	}
}

void	draw_forward_back(t_setup *setup)
{
	if (setup->key.forward == 1)
	{
		if (setup->map[(int)(setup->game.pos_y)][(int)(setup->game.pos_x \
					+ setup->game.dir_x * setup->game.movespeed)] == 'V')
			setup->game.pos_x += setup->game.dir_x * setup->game.movespeed;
		if (setup->map[(int)(setup->game.pos_y + setup->game.dir_y * \
			setup->game.movespeed)][(int)(setup->game.pos_x)] == 'V')
			setup->game.pos_y += setup->game.dir_y * setup->game.movespeed;
	}
	if (setup->key.back == 1)
	{
		if (setup->map[(int)(setup->game.pos_y)][(int)(setup->game.pos_x \
					- setup->game.dir_x * setup->game.movespeed)] == 'V')
			setup->game.pos_x -= setup->game.dir_x * setup->game.movespeed;
		if (setup->map[(int)(setup->game.pos_y - setup->game.dir_y * \
					setup->game.movespeed)][(int)(setup->game.pos_x)] == 'V')
			setup->game.pos_y -= setup->game.dir_y * setup->game.movespeed;
	}
}

void	draw_left_right(t_setup *setup)
{
	if (setup->key.right == 1)
	{
		if (setup->map[(int)(setup->game.pos_y)][(int)(setup->game.pos_x + \
					setup->game.dir_y * setup->game.movespeed)] == 'V')
			setup->game.pos_x += setup->game.dir_y * setup->game.movespeed;
		if (setup->map[(int)(setup->game.pos_y - setup->game.dir_x * \
					setup->game.movespeed)][(int)(setup->game.pos_x)] == 'V')
			setup->game.pos_y -= setup->game.dir_x * setup->game.movespeed;
	}
	if (setup->key.left == 1)
	{
		if (setup->map[(int)(setup->game.pos_y)][(int)(setup->game.pos_x - \
					setup->game.dir_y * setup->game.movespeed)] == 'V')
			setup->game.pos_x -= setup->game.dir_y * setup->game.movespeed;
		if (setup->map[(int)(setup->game.pos_y + setup->game.dir_x * \
					setup->game.movespeed)][(int)(setup->game.pos_x)] == 'V')
			setup->game.pos_y += setup->game.dir_x * setup->game.movespeed;
	}
}
