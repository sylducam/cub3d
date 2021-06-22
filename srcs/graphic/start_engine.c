/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_engine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:18:03 by sylducam          #+#    #+#             */
/*   Updated: 2021/06/22 16:18:07 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw(t_setup *setup)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < setup->height)
	{
		while (x <= setup->width)
		{
			setup->img.data[y * setup->width + x] = setup->game.buf[y][x];
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(setup->mlx, setup->win, setup->img.img, 0, 0);
}

int	main_loop(t_setup *setup)
{
	setup->x = 0;
	while (setup->x < setup->width)
	{
		calcul_raycast(setup);
		setup->x++;
	}
	draw(setup);
	key_press(setup);
	return (0);
}

int	start_engine(t_setup *setup)
{
	setup->mlx = mlx_init();
	init_value(setup);
	alloc_storage(setup);
	load_texture(setup);
	setup->win = mlx_new_window(setup->mlx, setup->width, setup->height, \
	"cub3d");
	if (setup->win == NULL)
		abort_prog("Failed to initialize new window");
	setup->img.img = mlx_new_image(setup->mlx, setup->width, setup->height);
	if (setup->img.img == NULL)
		abort_prog("Failed to initialize new image");
	setup->img.data = (int *)mlx_get_data_addr(setup->img.img, &setup->img.bpp \
	, &setup->img.size_l, &setup->img.endian);
	if (setup->img.data == NULL)
		abort_prog("Failed to get the image data address");
	mlx_hook(setup->win, 2, 0, &key_press_mouvement, setup);
	mlx_loop_hook(setup->mlx, &main_loop, setup);
	mlx_hook(setup->win, 3, 0, &key_release, setup);
	mlx_hook(setup->win, 17, 1L << 17, &exit_skip, setup);
	mlx_loop(setup->mlx);
	return (0);
}

void	init_value(t_setup *setup)
{
	setup->game.movespeed = 0.025;
	setup->game.rotspeed = 0.025;
	setup->game.map_x = 0;
	setup->game.map_y = 0;
	setup->width = 1280;
	setup->height = 720;
}

void	calcul_raycast(t_setup *setup)
{
	ray_dir(setup);
	detect_case(setup);
	ray_len(setup);
	calc_step_x(setup);
	calc_step_y(setup);
	dda_algo(setup);
	fisheye(setup);
	height_wall(setup);
	fill_stripe(setup);
	tex_orientation(setup);
	draw_texture(setup);
	draw_celling_floor(setup);
}
