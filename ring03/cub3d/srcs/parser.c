/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:44:41 by monie             #+#    #+#             */
/*   Updated: 2020/10/27 23:09:41 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

t_image				load_image(t_window *win, const char *line)
{
	t_image		img;

	img.img = mlx_xpm_file_to_image(win->mlx, (char *)line, \
													&img.width, &img.height);
	if (img.img == NULL)
		bad_config_exit();
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.ll, &img.end);
	return (img);
}

t_resolution		get_resolution(const char **buffer)
{
	t_resolution	resolution;

	if (!(buffer[1] && buffer[2]))
		bad_config_exit();
	resolution.x = ft_atoi(buffer[1]);
	resolution.y = ft_atoi(buffer[2]);
	if (resolution.x == 0 || resolution.y == 0)
		bad_config_exit();
	return (resolution);
}

static int			fill_element(t_window *window, const char *line)
{
	char **buffer;

	buffer = ft_split(line, SPACE_C);
	return (get_element(window, buffer));
}

static void			get_elements(t_window *window, int config_fd)
{
	size_t	index;
	char	*line;
	int		read_status;

	line = NULL;
	index = 0;
	while ((read_status = get_next_line(config_fd, &line)) == 1)
	{
		index += fill_element(window, line);
		free(line);
		line = NULL;
		if (index == NUMBER_OF_ELEMENTS)
			break ;
	}
	if (index < NUMBER_OF_ELEMENTS || read_status == 0)
		bad_config_exit();
}

void				parse(t_window *window, int argc, char **argv)
{
	int		config_fd;

	if (argc < 2)
		exit(ERROR);
	config_fd = open(argv[1], O_RDONLY);
	if (ft_strnstr(argv[1], ".cub", INT_MAX) == 0)
		bad_config_exit();
	if (config_fd == -1)
		exit(ERROR);
	get_elements(window, config_fd);
	if (window->config.r.x > MAX_WIDTH)
		window->config.r.x = MAX_WIDTH;
	if (window->config.r.y > MAX_HEIGHT)
		window->config.r.y = MAX_HEIGHT;
	get_map(window, config_fd);
	analyze_config(window);
	analyze_map(window->map);
	close(config_fd);
}
