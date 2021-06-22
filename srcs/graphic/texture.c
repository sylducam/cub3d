/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:18:19 by sylducam          #+#    #+#             */
/*   Updated: 2021/06/22 16:18:22 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#define TEXWIDTH 64
#define TEXHEIGHT 64

void	draw_texture(t_setup *setup)
{
	if (setup->game.side == 0)
		setup->game.wall_x = setup->game.pos_y + \
		setup->game.perpwalldist * setup->game.raydir_y;
	else
		setup->game.wall_x = setup->game.pos_x + \
		setup->game.perpwalldist * setup->game.raydir_x;
	setup->game.wall_x -= floor(setup->game.wall_x);
	setup->game.tex_x = (int)(setup->game.wall_x * (double)TEXWIDTH);
	if (setup->game.side == 0 && setup->game.raydir_x > 0)
		setup->game.tex_x = TEXWIDTH - setup->game.tex_x - 1;
	if (setup->game.side == 1 && setup->game.raydir_y < 0)
		setup->game.tex_x = TEXWIDTH - setup->game.tex_x - 1;
	setup->game.step = 1.0 * TEXHEIGHT / setup->game.lineheight;
	setup->game.tex_pos = (setup->game.drawstart - setup->height \
	 / 2 + setup->game.lineheight / 2) * setup->game.step;
	 draw_to_buff(setup);
}

void	draw_to_buff(t_setup *setup)
{
	int	y;

	y = setup->game.drawstart - 1;
	while (y < setup->game.drawend)
	{
		y++;
		setup->game.tex_y = (int)setup->game.tex_pos & (TEXHEIGHT - 1);
		setup->game.tex_pos += setup->game.step;
		setup->game.color = setup->game.texture[setup->game.texdir] \
		[TEXHEIGHT * setup->game.tex_y + setup->game.tex_x];
		if (setup->game.side == 1)
			setup->game.color = (setup->game.color >> 1) & 8355711;
		setup->game.buf[y][setup->x] = setup->game.color;
	}
}

void	tex_orientation(t_setup *setup)
{
	if (setup->game.side == 0 && setup->game.raydir_x < 0)
		setup->game.texdir = 3;
	if (setup->game.side == 0 && setup->game.raydir_x >= 0)
		setup->game.texdir = 2;
	if (setup->game.side == 1 && setup->game.raydir_y < 0)
		setup->game.texdir = 1;
	if (setup->game.side == 1 && setup->game.raydir_y >= 0)
		setup->game.texdir = 0;
	if (setup->game.side == 0)
		setup->game.wall_x = setup->game.pos_y + setup->game.perpwalldist \
		* setup->game.raydir_y;
	else
		setup->game.wall_x = setup->game.pos_x + setup->game.perpwalldist * \
		setup->game.raydir_x;
	setup->game.wall_x -= floor((setup->game.wall_x));
}

void	load_image(t_setup *setup, int *texture, char *path)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	setup->img.img = mlx_xpm_file_to_image(setup->mlx, path, \
	 &setup->img.img_width, &setup->img.img_height);
	if (setup->img.img_width != 64 || setup->img.img_height != 64 \
	|| setup->img.img == NULL)
		abort_prog("Only non-empty, 64x64 .xpm textures are supported.");
	if (setup->game.texture[0] == NULL)
		alloc_storage(setup);
	setup->img.data = (int *)mlx_get_data_addr(setup->img.img, \
	&setup->img.bpp, &setup->img.size_l, &setup->img.endian);
	while (y < setup->img.img_height)
	{
		while (x < setup->img.img_width)
		{
			texture[setup->img.img_width * y + x] = \
			setup->img.data[setup->img.img_width * y + x];
			x++;
		}
		x = 0;
		y++;
	}
}

void	load_texture(t_setup *setup)
{
	load_image(setup, setup->game.texture[0], setup->north_texture_path);
	load_image(setup, setup->game.texture[1], setup->south_texture_path);
	load_image(setup, setup->game.texture[2], setup->west_texture_path);
	load_image(setup, setup->game.texture[3], setup->east_texture_path);
}
