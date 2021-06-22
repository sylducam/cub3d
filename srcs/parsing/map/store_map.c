/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:14:55 by sylducam          #+#    #+#             */
/*   Updated: 2021/06/22 16:14:59 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	tab_cpy(t_setup *setup, char **temp)
{
	int	y;

	y = 0;
	while (setup->map[y])
	{
		temp[y] = ft_strdup(setup->map[y]);
		if (temp[y] == NULL)
			abort_prog("Failed to malloc setup->map[y]");
		y++;
	}
	return (y);
}

static void	add_map_line(char *line, t_setup *setup)
{
	int		size;
	int		y;
	char	**temp;

	size = 0;
	y = 0;
	while (setup->map[size])
	{
		if (size == 2147483647 && setup->map[size])
			abort_prog("Your map is too big");
		size++;
	}
	size++;
	temp = (char **)wrmalloc(sizeof(char *) * size + 1);
	if (temp == NULL)
		abort_prog("Failed to malloc setup->map");
	y = tab_cpy(setup, temp);
	temp[y] = ft_strdup(line);
	if (temp[y] == NULL)
		abort_prog("Failed to malloc setup->map[y]");
	temp[y + 1] = 0;
	free_char_p2p(setup->map);
	setup->map = temp;
}

void	store_map(char *line, t_setup *setup)
{
	if (setup->map == NULL)
	{
		setup->map = (char **)wrmalloc(sizeof(char *) + 1);
		if (setup->map == NULL)
			abort_prog("Failed to malloc setup->map");
		setup->map[0] = ft_strdup(line);
		if (setup->map[0] == NULL)
			abort_prog("Failed to malloc setup->map[0]");
		setup->map[1] = 0;
	}
	else
		add_map_line(line, setup);
}
