/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:44:41 by monie             #+#    #+#             */
/*   Updated: 2020/10/27 23:08:26 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

t_image			*detect_wall(t_window *win, double direction, char xy)
{
	if (direction > 2 * M_PI)
		direction -= 2 * M_PI;
	if (direction < 0)
		direction += 2 * M_PI;
	if (direction <= M_PI && xy == REACHED_X)
		return (&win->config.walls.so);
	else if (direction <= M_PI_2 && xy == REACHED_Y)
		return (&win->config.walls.ea);
	else if (direction <= M_PI && xy == REACHED_Y)
		return (&win->config.walls.we);
	else if (direction > M_PI && xy == REACHED_X)
		return (&win->config.walls.no);
	else if (direction >= M_PI && direction <= M_PI + M_PI_2 && xy == REACHED_Y)
		return (&win->config.walls.we);
	else if (direction >= M_PI + M_PI_2 && xy == REACHED_Y)
		return (&win->config.walls.ea);
	return (&win->config.walls.ea);
}

void			get_3d(t_window *win)
{
	double				current_direction;
	int					x;

	win->img.img = mlx_new_image(win->mlx, win->config.r.x, win->config.r.y);
	win->img.addr = mlx_get_data_addr(win->img.img, &win->img.bpp, \
	&win->img.ll, &win->img.end);
	if (!(win->heights = malloc(sizeof(int) * win->config.r.x)))
		exit(1);
	set_sprites(win);
	draw_background(win);
	current_direction = win->player.direction - M_PI / 3 / 2;
	win->player.direction_max = (win->player.direction + M_PI / 3 / 2) - \
		M_PI / 3 / win->config.r.x;
	x = 0;
	while (current_direction < win->player.direction_max)
	{
		draw_line(win, current_direction, x, win->heights);
		current_direction += M_PI / 3 / win->config.r.x;
		x++;
	}
	draw_sprites(win);
	free(win->heights);
	free(win->sprites.sprites);
}
