/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:44:41 by monie             #+#    #+#             */
/*   Updated: 2020/10/27 23:09:51 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void		convert(unsigned char *str, unsigned int size)
{
	str[0] = (unsigned char)(size);
	str[1] = (unsigned char)(size >> 8);
	str[2] = (unsigned char)(size >> 16);
	str[3] = (unsigned char)(size >> 24);
}

static void		head(t_window *win, unsigned int size_bmp, int fd)
{
	unsigned int	i;
	unsigned char	str[54];

	i = 0;
	while (i < 54)
		str[i++] = (unsigned char)(0);
	str[0] = (unsigned char)('B');
	str[1] = (unsigned char)('M');
	convert(str + 2, size_bmp);
	str[10] = (unsigned char)(54);
	str[14] = (unsigned char)(40);
	convert(str + 18, win->config.r.x);
	convert(str + 22, win->config.r.y);
	str[26] = (unsigned char)(1);
	str[28] = (unsigned char)(24);
	if (!(write(fd, str, 54)))
		return ;
}

static void		create_bmp_2(t_window *win, t_image *img, int fd)
{
	int				i;
	int				j;
	unsigned int	color;

	i = win->config.r.y - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < win->config.r.x)
		{
			color = *(unsigned int*)(img->addr + (i * img->ll + j *
				(img->bpp / 8)));
			j++;
			if (!(write(fd, &color, 3)))
				return ;
		}
		i--;
	}
}

static void		create_bmp(t_image *img, t_window *win)
{
	unsigned int	size_bmp;
	int				fd;

	if ((fd = open("screenshot.bmp", O_CREAT | O_TRUNC | O_WRONLY | O_APPEND,
		0666)) == -1)
		return ;
	size_bmp = 54 + (win->config.r.x * \
					win->config.r.y * 4);
	head(win, size_bmp, fd);
	create_bmp_2(win, img, fd);
	close(fd);
	exit(0);
}

void			make_screenshot(t_window *win, char **argv)
{
	if (ft_strncmp(SCREENSHOT_ARG_NAME, argv[2], INT_MAX) != 0)
		return ;
	while (win->config.r.x % 64 != 0)
		win->config.r.x--;
	while (win->config.r.y % 64 != 0)
		win->config.r.y--;
	get_3d(win);
	create_bmp(&win->img, win);
}
