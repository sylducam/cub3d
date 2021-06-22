/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:36:44 by sylducam          #+#    #+#             */
/*   Updated: 2021/06/21 13:25:31 by sylducam         ###   ########lyon.fr   */
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
	setup->game.c_color.chan.red = rgb[2];
	setup->game.c_color.chan.green = rgb[1];
	setup->game.c_color.chan.blue = rgb[0];
	return (0);
}

static int	right_content(t_setup *setup)
{
	char	**tab_rgb;

	tab_rgb = NULL;
	if (count_lines(setup->elements) != 2
		|| ft_strcmp(setup->elements[0], "C") != 0)
		return (-1);
	tab_rgb = ft_split(setup->elements[1], ',');
	if (tab_rgb == NULL)
		abort_prog("Failed to malloc tab_rgb");
	if (count_lines(tab_rgb) != 3 || is_tab_digit(tab_rgb) == -1
		|| store_rgb(tab_rgb, setup) == -1)
		return (-1);
	return (0);
}

void	ceiling(char *line, t_setup *setup)
{
	if (setup->b_ceiling == true)
		abort_prog("C identifier is used more than once");
	setup->elements = ft_split(line, ' ');
	if (setup->elements == NULL)
		abort_prog("Failed to malloc setup->elements");
	if (right_content(setup) == -1)
		abort_prog("Usage : C r,g,b (with 0 >= r/g/b <= 255)");
	setup->b_ceiling = true;
	wrfree(setup->elements);
}
