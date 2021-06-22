/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   south_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:16:38 by sylducam          #+#    #+#             */
/*   Updated: 2021/06/22 16:16:41 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	checking(t_setup *setup)
{
	int	fd;

	fd = 0;
	if (count_lines(setup->elements) != 2
		|| ft_strcmp(setup->elements[0], "SO") != 0
		|| format_check(setup->elements[1], ".xpm") == -1)
		return (-1);
	fd = open(setup->elements[1], O_DIRECTORY);
	if (fd >= 0)
		abort_prog("One of your textures is a directory, not a real .xpm");
	fd = open(setup->elements[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	return (0);
}

void	south_texture(char *line, t_setup *setup)
{
	if (setup->south == true)
		abort_prog("SO (south) identifier is used more than once");
	setup->elements = ft_split(line, ' ');
	if (checking(setup) == -1)
		abort_prog("Usage : SO ./path_without_spaces.xpm");
	setup->south_texture_path = ft_strdup(setup->elements[1]);
	if (setup->south_texture_path == NULL)
		abort_prog("Failed to malloc setup->south_texture_path");
	setup->south = true;
}
