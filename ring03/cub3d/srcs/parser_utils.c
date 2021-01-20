/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:44:41 by monie             #+#    #+#             */
/*   Updated: 2020/10/27 23:09:34 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	check_color(int r, int g, int b)
{
	if (r < 0 || r > 255)
		bad_config_exit();
	if (g < 0 || g > 255)
		bad_config_exit();
	if (b < 0 || b > 255)
		bad_config_exit();
}

void		check_buffer(char **buffer)
{
	if (*buffer)
		if (ft_strncmp(buffer[0], NO, INT_MAX) != 0 && ft_strncmp(buffer[0], \
			SO, INT_MAX) != 0 && ft_strncmp(buffer[0], EA, INT_MAX) != 0 && \
			ft_strncmp(buffer[0], WE, INT_MAX) != 0 && ft_strncmp(buffer[0], \
			R, INT_MAX) != 0 && ft_strncmp(buffer[0], S, INT_MAX) != 0 && \
			ft_strncmp(buffer[0], F, INT_MAX) != 0 && ft_strncmp(buffer[0], \
			C, INT_MAX) != 0)
			bad_config_exit();
}

int			get_element(t_window *window, char **buffer)
{
	if (buffer && buffer[0] != NULL)
	{
		check_buffer(buffer);
		if (ft_strncmp(buffer[0], NO, INT_MAX) == 0)
			window->config.walls.no = load_image(window, buffer[1]);
		else if (ft_strncmp(buffer[0], SO, INT_MAX) == 0)
			window->config.walls.so = load_image(window, buffer[1]);
		else if (ft_strncmp(buffer[0], EA, INT_MAX) == 0)
			window->config.walls.ea = load_image(window, buffer[1]);
		else if (ft_strncmp(buffer[0], WE, INT_MAX) == 0)
			window->config.walls.we = load_image(window, buffer[1]);
		else if (ft_strncmp(buffer[0], R, INT_MAX) == 0)
			window->config.r = get_resolution((const char **)buffer);
		else if (ft_strncmp(buffer[0], S, INT_MAX) == 0)
			window->config.s = load_image(window, buffer[1]);
		else if (ft_strncmp(buffer[0], F, INT_MAX) == 0)
			window->config.f = set_color((const char **)buffer);
		else if (ft_strncmp(buffer[0], C, INT_MAX) == 0)
			window->config.c = set_color((const char **)buffer);
		clear_arr(buffer);
		return (1);
	}
	clear_arr(buffer);
	return (0);
}

void		analyze_config(t_window *win)
{
	if (win->config.r.y <= 0 || win->config.r.x <= 0)
		bad_config_exit();
}

int			set_color(const char **buffer)
{
	int		r;
	int		g;
	int		b;
	char	**colors;

	if (!(buffer[1]))
		bad_config_exit();
	colors = ft_split(buffer[1], COMMA_C);
	if (!(colors[0] && colors[1] && colors[2]))
		bad_config_exit();
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	clear_arr(colors);
	check_color(r, g, b);
	return ((r << 16) | (g << 8) | b);
}
