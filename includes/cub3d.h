/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigoncal <nigoncal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:00:12 by sylducam          #+#    #+#             */
/*   Updated: 2021/06/22 11:58:41 by nigoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define COLOR_MAX 255
# define ERROR -1
# define RAS 0

# define ROTATE_LEFT		123
# define ROTATE_RIGHT		124
# define MOVE_A				0
# define MOVE_D				2
# define MOVE_W				13
# define MOVE_S				1
# define MAJ				12
# define EXIT_ESC			53

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <string.h>
# include <strings.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef union u_color
{
	struct	s_chan
	{
		uint8_t	red;
		uint8_t	green;
		uint8_t	blue;
	}		chan;
	uint32_t	color;
}				t_col;

typedef struct s_game
{
	t_col		f_color;
	t_col		c_color;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;

	double		raydir_x;
	double		raydir_y;
	double		camera_x;
	double		wall_x;
	int			map_x;
	int			map_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		perpwalldist;
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		movespeed;
	double		rotspeed;
	int			width;
	int			height;
	int			texdir;
	int			**texture;
	int			color;
	int			tex_y;
	int			tex_x;
	double		step;
	double		tex_pos;
	int			buf[720][1280];
	void		*image;
}				t_game;

typedef struct s_key {
	int	forward;
	int	back;
	int	left;
	int	right;
	int	rotate_left;
	int	rotate_right;
	int	sprint;
	int	count_key;
}				t_key;

typedef struct s_setup
{
	void	*win;
	void	*mlx;
	int		north_format;
	int		south_format;
	int		east_format;
	int		west_format;
	bool	north;
	bool	south;
	bool	east;
	bool	west;
	bool	b_floor;
	bool	b_ceiling;
	bool	map_started;
	bool	map_over;
	int		id_counter;
	char	**elements;
	char	*north_texture_path;
	char	*south_texture_path;
	char	*west_texture_path;
	char	*east_texture_path;
	char	**map;
	char	**squared_map;
	int		map_xsize;
	int		map_ysize;
	char	player_dir;
	int		width;
	int		height;
	int		x;
	int		y;
	t_img	img;
	t_game	game;
	t_key	key;
}				t_setup;

/* PARSING */

void			abort_prog(char *s);
int				non_empty_line(char *line);
void			parse_id(char *line, t_setup *setup);
void			textures(char *line, t_setup *setup);
void			north_texture(char *line, t_setup *setup);
void			south_texture(char *line, t_setup *setup);
void			east_texture(char *line, t_setup *setup);
void			west_texture(char *line, t_setup *setup);
void			parse_floor(char *line, t_setup *setup);
void			ceiling(char *line, t_setup *setup);
void			parse_map(char *line, t_setup *setup);
void			store_map(char *line, t_setup *setup);
void			square_map(t_setup *setup);
void			check_map(t_setup *setup);

/* GRAPHIC */

void			dda(t_setup *setup);
void			fill_stripe(t_setup *setup);
void			height_wall(t_setup *setup);
void			ray_dir(t_setup *setup);
void			detect_case(t_setup *setup);
void			ray_len(t_setup *setup);
void			dda_algo(t_setup *setup);
void			fisheye(t_setup *setup);
int				key_release(int key, t_setup *setup);
int				key_press_mouvement(int key, t_setup *setup);
void			key_draw_rotate(t_setup *setup);
int				key_press(t_setup *setup);
int				start_engine(t_setup *setup);
void			init_buf(t_setup *setup);
void			alloc_storage(t_setup *setup);
void			tex_orientation(t_setup *setup);
void			load_texture(t_setup *setup);
void			graph_textures(t_setup *setup);
void			draw_texture(t_setup *setup);
void			draw_celling_floor(t_setup *setup);
void			draw(t_setup *setup);
void			draw_rotate_right(t_setup *setup);
void			draw_rotate_left(t_setup *setup);
void			draw_forward_back(t_setup *setup);
void			draw_left_right(t_setup *setup);
void			calcul_raycast(t_setup *setup);
void			calcul_texture(t_setup *setup);
void			calc_step_x(t_setup *setup);
void			calc_step_y(t_setup *setup);
int				exit_skip(void);
void			init_value(t_setup *setup);
void			draw_to_buff(t_setup *setup);

#endif
