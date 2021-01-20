/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 17:08:37 by monie             #+#    #+#             */
/*   Updated: 2020/07/25 13:13:47 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		free_it(char **str)
{
	free(*str);
	*str = NULL;
}

static void		remain_and_free(char **remain, int readed)
{
	char			*tmp;

	readed++;
	tmp = ft_strdup(*remain + readed, ft_strlen(*remain + readed));
	free(*remain);
	*remain = ft_strdup(tmp, ft_strlen(tmp));
	free_it(&tmp);
}

static int		find_n(char **remain, int fd)
{
	char			*buf;
	char			*tmp;
	char			*n;
	ssize_t			i;

	while (!(n = ft_strchr(*remain, '\n')))
	{
		buf = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if ((i = read(fd, buf, BUFFER_SIZE)) < 0)
		{
			free_it(&buf);
			return (-2);
		}
		buf[i] = '\0';
		if (i == 0)
		{
			free_it(&buf);
			return (-1);
		}
		tmp = *remain;
		*remain = ft_strjoin(*remain, buf);
		free_it(&tmp);
		free_it(&buf);
	}
	return (n - *remain);
}

int				get_next_line(int fd, char **line)
{
	static char		*remain;
	int				readed;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	if (!remain)
		remain = ft_strdup("", 0);
	if ((readed = find_n(&remain, fd)) == -2)
	{
		free_it(&remain);
		return (-1);
	}
	if (readed == -1)
	{
		*line = ft_strdup(remain, ft_strlen(remain));
		free_it(&remain);
		return (0);
	}
	*line = ft_strdup(remain, readed);
	remain_and_free(&remain, readed);
	return (1);
}
