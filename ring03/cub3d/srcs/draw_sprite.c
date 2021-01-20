/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:44:41 by monie             #+#    #+#             */
/*   Updated: 2020/10/27 23:08:20 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static int		get_s_color(t_window *win, double x, double y, double height)
{
	unsigned int		color;
	char				*dst;
	double				new_y;
	double				new_x;

	new_y = y * ((double)win->config.s.height / height);
	new_x = x * ((double)win->config.s.width / height);
	dst = win->config.s.addr + (int)new_y * win->config.s.ll + ((int)new_x * \
		(win->config.s.bpp / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void			put_s_to_imgage(t_window *win, double hitx, double spr_size, \
																	double dir)
{
	double		x;
	double		y;
	double		hity;
	t_position	xy;
	int			color;

	x = 0;
	hity = ((double)win->config.r.y - spr_size) / 2;
	while (x < spr_size)
	{
		y = 0;
		while (y < spr_size)
		{
			xy.x = hitx + x;
			xy.y = hity + y;
			if (xy.x >= 0 && xy.x < (double)win->config.r.x && fabs(dir - \
			win->player.direction) < M_PI / 3 && xy.y >= 0 && xy.y < \
			(double)win->config.r.y && (color = get_s_color(win, x, y, \
			spr_size)) != 0 && win->heights[(int)xy.x] > \
			(int)((double)win->config.r.y / (spr_size / SCALE)))
				pixel_put(win, xy, color);
			y++;
		}
		x++;
	}
}

static void		draw_sprite(t_window *win, t_sprite sprite)
{
	double		dir;
	double		hitx;
	double		spr_size;

	spr_size = (double)win->config.r.y / (sprite.distance / SCALE);
	dir = atan2(sprite.pos.y - win->player.position.y, sprite.pos.x - \
	win->player.position.x);
	while (dir - win->player.direction > M_PI)
		dir -= 2 * M_PI;
	while (dir - win->player.direction < -M_PI)
		dir += 2 * M_PI;
	if (dir > win->player.direction)
		hitx = (double)win->config.r.x / 2 + sprite.distance * sin(dir - \
		win->player.direction) * ((double)win->config.r.x / (sprite.distance)) \
		- spr_size / 2;
	else if (dir < win->player.direction)
		hitx = (double)win->config.r.x / 2 - sprite.distance * \
		sin(win->player.direction - dir) * ((double)win->config.r.x / \
		(sprite.distance)) - spr_size / 2;
	else
		hitx = (double)win->config.r.x / 2 - spr_size / 2;
	put_s_to_imgage(win, hitx, spr_size, dir);
}

void			draw_sprites(t_window *win)
{
	size_t		index;

	index = 0;
	while (index < win->sprites.quantity)
	{
		if (win->sprites.sprites[index].distance > 60)
			draw_sprite(win, win->sprites.sprites[index]);
		index++;
	}
}
