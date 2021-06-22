/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   east_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:15:52 by sylducam          #+#    #+#             */
/*   Updated: 2021/06/22 16:16:27 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	checking(t_setup *setup)
{
	int	fd;

	fd = 0;
	if (count_lines(setup->elements) != 2
		|| ft_strcmp(setup->elements[0], "EA") != 0
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

void	east_texture(char *line, t_setup *setup)
{
	if (setup->east == true)
		abort_prog("EA (east) identifier is used more than once");
	setup->elements = ft_split(line, ' ');
	if (checking(setup) == -1)
		abort_prog("Usage : EA ./path_without_spaces.xpm");
	setup->east_texture_path = ft_strdup(setup->elements[1]);
	if (setup->east_texture_path == NULL)
		abort_prog("Failed to malloc setup->east_texture_path");
	setup->east = true;
}
