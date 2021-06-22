/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:13:37 by sylducam          #+#    #+#             */
/*   Updated: 2021/06/22 16:13:42 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parse_id(char *line, t_setup *setup)
{
	line = change_char(line, ' ', '\t');
	line = change_char(line, ' ', '\v');
	while (*line == ' ')
		line++;
	if (*line == 'N' || *line == 'S' || *line == 'E' || *line == 'W')
		textures(line, setup);
	else if (*line == 'F')
		parse_floor(line, setup);
	else if (*line == 'C')
		ceiling(line, setup);
	else if (*line == '\0')
		return ;
	else
		abort_prog("Identifiers allowed and mandatory : NO,SO,WE,EA,S,F,C. \
Note that they need to be all BEFORE the map.");
}
