/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:44:41 by monie             #+#    #+#             */
/*   Updated: 2020/10/27 23:21:14 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void		set_map_width(t_window *win, t_list *list_map)
{
	t_list	*tmp;

	tmp = list_map;
	while (tmp)
	{
		if (ft_strlen(tmp->content) > win->map_width)
			win->map_width = ft_strlen(tmp->content);
		tmp = tmp->next;
	}
}

static char		**make_map(t_window *win, t_list *list_map)
{
	char	**map;
	size_t	index;
	t_list	*tmp;

	set_map_width(win, list_map);
	if (!(map = malloc(sizeof(char *) * (ft_lstsize(list_map) + 1))))
		exit(ERROR);
	index = 0;
	tmp = list_map;
	while (tmp)
	{
		map[index] = malloc(sizeof(char) * (win->map_width + 1));
		ft_bzero(map[index], win->map_width);
		ft_strlcpy(map[index], tmp->content, INT_MAX);
		tmp = tmp->next;
		index++;
	}
	ft_lstclear(&list_map, &free);
	map[index] = NULL;
	return (map);
}

static void		add_line_to_map(t_list **map, char *line)
{
	t_list	*buffer;

	if (!(buffer = ft_lstnew(ft_strdup(line))))
		exit(ERROR);
	ft_lstadd_back(map, buffer);
}

void			get_map(t_window *win, int config_fd)
{
	char	*line;
	t_list	*list_map;
	size_t	read_r;
	int		started;

	list_map = NULL;
	line = NULL;
	started = 0;
	while ((read_r = get_next_line(config_fd, &line)) >= 0)
	{
		if ((unsigned int)*line != 0)
		{
			started = 1;
			add_line_to_map(&list_map, line);
		}
		if ((unsigned int)*line == 0 && started)
		{
			free(line);
			break ;
		}
		free(line);
		if (read_r == 0)
			break ;
	}
	win->map = make_map(win, list_map);
}
