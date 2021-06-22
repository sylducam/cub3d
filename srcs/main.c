/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:13:12 by sylducam          #+#    #+#             */
/*   Updated: 2021/06/22 16:13:16 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	start_parsing(int fd, char **line, t_setup *setup)
{
	while (get_next_line(fd, line))
	{
		if (setup->id_counter < 6)
		{
			setup->id_counter += non_empty_line(*line);
			parse_id(*line, setup);
		}
		else
		{
			if (setup->id_counter == 2147483647)
				abort_prog("Your map is too big");
			parse_map(*line, setup);
		}
	}
	if (setup->id_counter == 2147483647)
		abort_prog("Your map is too big");
	parse_map(*line, setup);
	if (!setup->map)
		abort_prog("The map is missing in your .cub file");
	square_map(setup);
	check_map(setup);
}

int	main(int argc, char **argv)
{
	t_setup		setup;
	int			fd;
	char		*line;

	line = NULL;
	ft_bzero(&setup, sizeof(setup));
	if (argc != 2 || (format_check(argv[1], ".cub")) == -1)
		abort_prog("Launch the program as follows\n./cub3d file.cub");
	fd = open(argv[1], O_DIRECTORY);
	if (fd != -1)
		abort_prog("Invalid .cub : yours is a directory.");
	fd = open(argv[1], O_RDONLY);
	if (fd < 2)
		abort_prog("While opening the .cub file");
	start_parsing(fd, &line, &setup);
	start_engine(&setup);
	wrdestroy();
	close(fd);
	return (0);
}
