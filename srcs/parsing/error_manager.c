/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:13:26 by sylducam          #+#    #+#             */
/*   Updated: 2021/06/22 16:13:32 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	map_error(void)
{
	ft_putstr("An error was spotted in your map\nRules of the map :\n");
	ft_putstr("The only characters allowed are 0 for the floor, ");
	ft_putstr("1 for the walls, N/S/E/W for the player ");
	ft_putstr("according to it's orientation and spaces.\n");
	ft_putstr("The map has to be closed by walls and space characters are ");
	ft_putstr("only allowed around the map to shape it to your will.");
	ft_putstr("Here's an example of a simple valid map :\n\n");
	ft_putstr("        1111111111111111111111111\n");
	ft_putstr("        1000000000110000000000001\n");
	ft_putstr("        1011000001110000000000001\n");
	ft_putstr("        1001000000000000000000001\n");
	ft_putstr("111111111011000001110000000000001\n");
	ft_putstr("100000000011000001110111111111111\n");
	ft_putstr("11110111111111011100000010001\n");
	ft_putstr("11110111111111011101010010001\n");
	ft_putstr("11000000110101011100000010001\n");
	ft_putstr("10000000000000001101010010001\n");
	ft_putstr("11000001110101011111011110N0111\n");
	ft_putstr("11110111 1110101 101111010001\n");
	ft_putstr("11111111 1111111 111111111111");
}

void	abort_prog(char *error_msg)
{
	ft_putstr("Error\n");
	if (*error_msg == 'M')
		map_error();
	else
		ft_putstr(error_msg);
	write (1, "\n", 1);
	wrdestroy();
	exit(1);
}
