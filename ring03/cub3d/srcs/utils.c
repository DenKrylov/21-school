/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:44:41 by monie             #+#    #+#             */
/*   Updated: 2020/10/27 23:10:01 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int				bad_char(const char c)
{
	if (c != NORTH_C && c != SOUTH_C && c != EAST_C && c != WEST_C
		&& c != WALL_C && c != EMPTY_C && c != SPRITE_C && c != SPACE_C)
		return (TRUE);
	return (NOT_FOUND);
}

void			bad_config_exit(void)
{
	ft_putstr_fd("Error\n", STD_ERROR_STREAM);
	ft_putstr_fd("BAD CONFIG.\n", STD_ERROR_STREAM);
	exit(1);
}

void			pixel_put(t_window *win, t_position pos, int color)
{
	char	*dst;

	dst = win->img.addr + ((int)pos.y * win->img.ll + \
		(int)pos.x * (win->img.bpp / 8));
	*(unsigned int *)dst = color;
}

double			find_hyp(t_window *win, double x1, double x2)
{
	return (sqrt(pow((double)(x2 + 0.5) * SCALE - win->player.position.x, \
		2) + pow((double)(x1 + 0.5) * SCALE - win->player.position.y, 2)));
}
