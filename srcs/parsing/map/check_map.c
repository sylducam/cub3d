/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:14:22 by sylducam          #+#    #+#             */
/*   Updated: 2021/06/22 16:14:27 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	flood_fill(char **map, int y, int x, t_setup *setup)
{
	if (map[y][x] == ' ')
		abort_prog("M");
	if ((map[y][x] == '2' && (x != 0 || x != setup->map_xsize
			|| y != 0 || y != setup->map_ysize)))
	{
		map[y][x] = 'X';
		flood_fill(map, y - 1, x, setup);
		flood_fill(map, y, x + 1, setup);
		flood_fill(map, y + 1, x, setup);
		flood_fill(map, y, x - 1, setup);
	}
	if ((map[y][x] == '0' || bool_strchr("NSEW", map[y][x]) != -1)
		&& (x != 0 || x != setup->map_xsize
		|| y != 0 || y != setup->map_ysize))
	{
		map[y][x] = 'V';
		flood_fill(map, y - 1, x, setup);
		flood_fill(map, y, x + 1, setup);
		flood_fill(map, y + 1, x, setup);
		flood_fill(map, y, x - 1, setup);
	}
}

static void	store_dir_xy(t_setup *setup)
{
	if (setup->player_dir == 'N')
	{
		setup->game.dir_y = -1;
		setup->game.plane_x = 0.66;
	}
	if (setup->player_dir == 'S')
	{
		setup->game.dir_y = 1;
		setup->game.plane_x = -0.66;
	}
	if (setup->player_dir == 'E')
	{
		setup->game.dir_x = 1;
		setup->game.plane_y = 0.66;
	}
	if (setup->player_dir == 'W')
	{
		setup->game.dir_x = -1;
		setup->game.plane_y = -0.66;
	}
}

static void	store_player(int y, int x, t_setup *setup)
{
	if (setup->player_dir)
		abort_prog("You can't have more than one player on the map");
	else
	{
		setup->player_dir = setup->map[y][x];
		setup->x = x;
		setup->y = y;
		setup->game.pos_x = (float)x + 0.5;
		setup->game.pos_y = (float)y + 0.5;
		store_dir_xy(setup);
	}
}

void	find_player(t_setup *setup)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (setup->map[y])
	{
		while (setup->map[y][x])
		{
			if (bool_strchr("NSEW", setup->map[y][x]) != -1)
				store_player(y, x, setup);
			x++;
		}
		y++;
		x = 0;
	}
	if (setup->player_dir == 0)
		abort_prog("No player found on the map");
}

void	check_map(t_setup *setup)
{
	find_player(setup);
	flood_fill(setup->map, setup->y, setup->x, setup);
}
