/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:44:41 by monie             #+#    #+#             */
/*   Updated: 2020/10/27 23:09:47 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static int			set_player(t_window *win, char c)
{
	if (c == NORTH_C || c == SOUTH_C || c == EAST_C || c == WEST_C)
	{
		if (c == SOUTH_C)
			win->player.direction = M_PI_2;
		else if (c == NORTH_C)
			win->player.direction = M_PI + M_PI_2;
		else if (c == EAST_C)
			win->player.direction = 0;
		else if (c == WEST_C)
			win->player.direction = M_PI;
		return (SUCCESS);
	}
	return (NOT_FOUND);
}

void				init_player(t_window *win)
{
	t_position	position;
	t_position	player_position;
	size_t		players;

	players = 0;
	while (win->map[(int)position.y] != NULL)
	{
		position.x = 0;
		while (position.x < win->map_width)
		{
			if (set_player(win, win->map[(int)position.y][(int)position.x]))
			{
				player_position = position;
				players++;
			}
			position.x++;
		}
		position.y++;
	}
	if (players != 1)
		bad_config_exit();
	player_position.x = (player_position.x + 0.5) * SCALE;
	player_position.y = (player_position.y + 0.5) * SCALE;
	win->player.position = player_position;
}
