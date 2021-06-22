/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 11:18:48 by sylducam          #+#    #+#             */
/*   Updated: 2021/06/21 13:24:43 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	store_rgb(char **tab_rgb, t_setup *setup)
{
	int	i;
	int	rgb[3];

	i = 0;
	while (tab_rgb[i])
	{
		rgb[i] = atoi_limit(tab_rgb[i], COLOR_MAX + 1);
		if (rgb[i] == COLOR_MAX + 1)
			return (-1);
		i++;
	}
	setup->game.f_color.chan.red = rgb[2];
	setup->game.f_color.chan.green = rgb[1];
	setup->game.f_color.chan.blue = rgb[0];
	return (0);
}

static int	right_content(t_setup *setup)
{
	char	**tab_rgb;

	tab_rgb = NULL;
	if (count_lines(setup->elements) != 2
		|| ft_strcmp(setup->elements[0], "F") != 0)
		return (-1);
	tab_rgb = ft_split(setup->elements[1], ',');
	if (tab_rgb == NULL)
		abort_prog("Failed to malloc tab_rgb");
	if (count_lines(tab_rgb) != 3 || is_tab_digit(tab_rgb) == -1
		|| store_rgb(tab_rgb, setup) == -1)
		return (-1);
	return (0);
}

void	parse_floor(char *line, t_setup *setup)
{
	if (setup->b_floor == true)
		abort_prog("F identifier is used more than once");
	setup->elements = ft_split(line, ' ');
	if (setup->elements == NULL)
		abort_prog("Failed to malloc setup->elements");
	if (right_content(setup) == -1)
		abort_prog("Usage : F r,g,b (with 0 >= r/g/b <= 255)");
	setup->b_floor = true;
	wrfree(setup->elements);
}
