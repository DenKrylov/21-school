/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:44:41 by monie             #+#    #+#             */
/*   Updated: 2020/10/27 23:08:32 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int			detect_color(t_line text, t_image *wall)
{
	unsigned int		color;
	char				*dst;
	double				new_y;
	double				new_x;

	new_y = text.pos.y * (wall->height / (double)text.height);
	new_x = text.pos.x * wall->width;
	dst = wall->addr + (int)new_y * wall->ll + ((int)new_x * (wall->bpp / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void		draw_background(t_window *win)
{
	t_position	xy;

	xy.y = 0;
	while (xy.y < win->config.r.y / 2)
	{
		xy.x = 0;
		while (xy.x < win->config.r.x)
		{
			pixel_put(win, xy, win->config.c);
			xy.x++;
		}
		xy.y++;
	}
	while (xy.y < win->config.r.y)
	{
		xy.x = 0;
		while (xy.x < win->config.r.x)
		{
			pixel_put(win, xy, win->config.f);
			xy.x++;
		}
		xy.y++;
	}
}

void		get_line_height(t_window *win, double dir, t_line *text)
{
	int			ray_length;
	t_position	ray;
	double		hity;

	ray_length = 0;
	ray = win->player.position;
	text->axis = 0;
	while (!(text->axis))
	{
		ray.x += cos(dir);
		if (win->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] == WALL_C)
			text->axis = REACHED_Y;
		ray.y += sin(dir);
		if (win->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] == WALL_C \
			&& !(text->axis))
			text->axis = REACHED_X;
		ray_length++;
	}
	text->pos.x = fabs(floor(ray.x / SCALE + 0.5) - ray.x / SCALE);
	hity = fabs(floor(ray.y / SCALE + 0.5) - ray.y / SCALE);
	if (hity > text->pos.x)
		text->pos.x = hity;
	text->distance = ray_length * fabs(cos(win->player.direction - dir));
	text->height = (win->config.r.y * SCALE) / (ray_length * \
		fabs(cos(win->player.direction - dir)));
}

void		draw_line(t_window *window, double current_direction, int x, \
	int *heights)
{
	t_position	line;
	int			buffer;
	t_image		*wall;
	t_line		text;

	get_line_height(window, current_direction, &text);
	heights[x] = text.distance;
	line.y = (window->config.r.y - text.height) / 2;
	line.x = x;
	buffer = text.height;
	text.pos.y = 0;
	wall = detect_wall(window, current_direction, text.axis);
	while (buffer-- && line.y < window->config.r.y)
	{
		if (line.y >= 0)
			pixel_put(window, line, detect_color(text, wall));
		line.y++;
		text.pos.y++;
	}
}

void		draw_3d(t_window *win)
{
	get_3d(win);
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
	mlx_destroy_image(win->mlx, win->img.img);
}
