/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:44:41 by monie             #+#    #+#             */
/*   Updated: 2020/10/27 23:09:56 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void			get_sprites(t_window *win)
{
	size_t			index1;
	size_t			index2;

	win->sprites.quantity = 0;
	index1 = 0;
	while ((win->map)[index1] != NULL)
	{
		index2 = 0;
		while ((win->map)[index1][index2] != '\0')
		{
			if ((win->map)[index1][index2] == SPRITE_C)
				win->sprites.quantity++;
			index2++;
		}
		index1++;
	}
	if (win->sprites.quantity)
		if (!(win->sprites.sprites = malloc(sizeof(t_sprite) * \
			win->sprites.quantity)))
			exit(1);
}

static void			sort_sprites(t_window *win)
{
	t_sprite	buffer;
	size_t		index1;
	size_t		index2;

	index1 = 0;
	index2 = 0;
	while (index1 < win->sprites.quantity - 1)
	{
		index2 = index1 + 1;
		while (index2 < win->sprites.quantity)
		{
			if (win->sprites.sprites[index1].distance < \
				win->sprites.sprites[index2].distance)
			{
				buffer = win->sprites.sprites[index1];
				win->sprites.sprites[index1] = win->sprites.sprites[index2];
				win->sprites.sprites[index2] = buffer;
			}
			index2++;
		}
		index1++;
	}
}

void				set_sprites(t_window *win)
{
	size_t		x1;
	size_t		x2;
	size_t		numb;

	get_sprites(win);
	if (!(win->sprites.quantity))
		return ;
	x1 = 0;
	numb = 0;
	while ((win->map)[x1] != NULL)
	{
		x2 = 0;
		while ((win->map)[x1][x2] != '\0')
		{
			if ((win->map)[x1][x2] == SPRITE_C)
			{
				win->sprites.sprites[numb].pos.x = ((double)x2 + 0.5) * SCALE;
				win->sprites.sprites[numb].pos.y = ((double)x1 + 0.5) * SCALE;
				win->sprites.sprites[numb++].distance = find_hyp(win, x1, x2);
			}
			x2++;
		}
		x1++;
	}
	sort_sprites(win);
}
