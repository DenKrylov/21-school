/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:44:41 by monie             #+#    #+#             */
/*   Updated: 2020/10/27 23:08:50 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void		return_player_back(t_window *window, t_position old)
{
	t_position		pos;

	pos = window->player.position;
	if (window->map[(int)pos.y / SCALE][(int)pos.x / SCALE] == WALL_C)
		window->player.position = old;
}

static void		try_to_move(int key, t_window *window)
{
	t_position		old_position;

	old_position = window->player.position;
	if (key == KEY_UP)
	{
		window->player.position.x += SPEED * cos(window->player.direction);
		window->player.position.y += SPEED * sin(window->player.direction);
	}
	if (key == KEY_DOWN)
	{
		window->player.position.x -= SPEED * cos(window->player.direction);
		window->player.position.y -= SPEED * sin(window->player.direction);
	}
	if (key == KEY_LEFT)
	{
		window->player.position.x += SPEED * sin(window->player.direction);
		window->player.position.y -= SPEED * cos(window->player.direction);
	}
	if (key == KEY_RIGHT)
	{
		window->player.position.x -= SPEED * sin(window->player.direction);
		window->player.position.y += SPEED * cos(window->player.direction);
	}
	return_player_back(window, old_position);
}

int				key_press(int key, t_window *window)
{
	if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT)
		try_to_move(key, window);
	if (key == KEY_LEFT_ARROW)
		window->player.direction -= 0.1;
	if (key == KEY_RIGHT_ARROW)
		window->player.direction += 0.1;
	if (key == KEY_ESCAPE)
		exit(0);
	if (window->player.direction < 0)
		window->player.direction += 2 * M_PI;
	else if (window->player.direction > 2 * M_PI)
		window->player.direction -= 2 * M_PI;
	draw_3d(window);
	return (0);
}
