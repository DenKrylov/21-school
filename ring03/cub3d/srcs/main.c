/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:44:41 by monie             #+#    #+#             */
/*   Updated: 2020/10/27 23:08:56 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int		main(int argc, char **argv)
{
	t_window	win;

	if (argc >= 2 && argc <= 3)
	{
		win.mlx = mlx_init();
		parse(&win, argc, argv);
		init_player(&win);
		if (argc == 3)
		{
			make_screenshot(&win, argv);
			ft_putstr_fd("Error!\nBad argv[2] name.\n", 1);
			exit(1);
		}
		win.win = mlx_new_window(win.mlx, win.config.r.x, win.config.r.y, \
			"cub3D");
		draw_3d(&win);
		mlx_hook(win.win, 2, (1L << 0), &key_press, &win);
		mlx_hook(win.win, 17, 0, &ft_close, &win);
		mlx_loop(win.mlx);
	}
	else
		ft_putstr_fd("Error!\nWrong number of args.\n", 1);
	return (0);
}
