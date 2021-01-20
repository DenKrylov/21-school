/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 17:37:33 by casteria          #+#    #+#             */
/*   Updated: 2020/10/27 23:21:43 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include "get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define ERROR -1
# define NOT_FOUND 0
# define STD_OUTPUT_STREAM 1
# define SCALE 64
# define SPEED 6
# define KEY_DOWN 1
# define KEY_UP 13
# define KEY_RIGHT 2
# define KEY_LEFT 0
# define KEY_LEFT_ARROW 123
# define KEY_RIGHT_ARROW 124
# define KEY_ESCAPE 53
# define WIN_WIDTH 640
# define WIN_HEIGHT 480
# define SPRITE_C '2'
# define WALL_C '1'
# define EMPTY_C '0'
# define ITEM 2
# define WALL 1
# define REACHED_X 'x'
# define REACHED_Y 'y'
# define REACHED_S 's'
# define NORTH_C 'N'
# define SOUTH_C 'S'
# define EAST_C 'E'
# define WEST_C 'W'
# define R "R"
# define NO "NO"
# define SO "SO"
# define WE "WE"
# define EA "EA"
# define S "S"
# define F "F"
# define C "C"
# define SPACE_C ' '
# define COMMA_C ','
# define NUMBER_OF_ELEMENTS 8
# define SCREENSHOT_ARG_NAME "--save"
# define MAX_HEIGHT 1440
# define MAX_WIDTH 2560

typedef	struct		s_position
{
	double			x;
	double			y;
}					t_position;

typedef struct		s_resolution
{
	int				x;
	int				y;
}					t_resolution;

typedef	struct		s_player
{
	t_position		position;
	double			direction;
	double			direction_max;
}					t_player;

typedef struct		s_image
{
	void			*img;
	char			*addr;
	int				bpp;
	int				ll;
	int				end;
	int				width;
	int				height;
}					t_image;

typedef struct		s_walls
{
	t_image			no;
	t_image			so;
	t_image			we;
	t_image			ea;
}					t_walls;

typedef struct		s_config
{
	t_resolution	r;
	t_walls			walls;
	t_image			s;
	int				f;
	int				c;
}					t_config;

typedef struct		s_line
{
	t_position		pos;
	int				height;
	int				distance;
	int				dir;
	char			obj;
	char			axis;
}					t_line;

typedef	struct		s_sprite
{
	t_position		pos;
	double			distance;
}					t_sprite;

typedef struct		s_sprite_arr
{
	t_sprite		*sprites;
	size_t			quantity;
}					t_sprite_arr;

typedef struct		s_map
{
	char			**map;
	size_t			width;
}					t_map;

typedef	struct		s_window
{
	void			*mlx;
	t_image			img;
	void			*win;
	char			**map;
	size_t			map_width;
	t_player		player;
	t_config		config;
	t_sprite_arr	sprites;
	int				*heights;
}					t_window;

void				get_map(t_window *win, int config_fd);
void				init_player(t_window *win);
void				pixel_put(t_window *win, t_position pos, int color);
int					key_press(int key, t_window *window);
void				draw_3d(t_window *win);
void				parse(t_window *win, int argc, char **argv);
int					bad_char(const char c);
t_image				*detect_wall(t_window *window, double current_direction, \
																char axis);
void				bad_config_exit();
int					detect_color(t_line text, t_image *wall);
void				set_sprites(t_window *win);
void				draw_sprites(t_window *win);
void				make_screenshot(t_window *win, char **argv);
void				get_3d(t_window *win);
void				draw_background(t_window *win);
void				get_line_height(t_window *win, double dir, t_line *text);
void				draw_line(t_window *window, double current_direction, \
														int x, int *heights);
void				clear_arr(char **arr);
int					ft_close(t_window *win);
void				check_buffer(char **buffer);
void				analyze_config(t_window *win);
double				find_hyp(t_window *win, double x1, double x2);
int					get_element(t_window *window, char **buffer);
t_image				load_image(t_window *win, const char *line);
int					set_color(const char **buffer);
t_resolution		get_resolution(const char **buffer);

void				analyze_map(char **map);

#endif
