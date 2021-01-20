/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:44:41 by monie             #+#    #+#             */
/*   Updated: 2020/10/27 22:19:41 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static int		check_cell(char **map, char c, int i, size_t j)
{
	if (c != 'N' && c != 'S' && c != 'W' && c != 'E' && c != '0' && c != '2')
	{
		if (c == '1' || c == ' ')
			return (0);
		else
			return (1);
	}
	if (map[i][j + 1] == ' ' || map[i][j - 1] == ' ' \
		|| map[i + 1][j] == ' ' || map[i - 1][j] == ' ' \
		|| map[i - 1][j + 1] == ' ' || map[i + 1][j + 1] == ' ' \
		|| map[i - 1][j - 1] == ' ' || map[i + 1][j - 1] == ' ')
		return (1);
	if (!(map[i - 1][j]) || !(map[i + 1][j]) ||\
		!(map[i - 1][j + 1]) || !(map[i + 1][j + 1]))
		return (1);
	return (0);
}

static int		check_bot_top(char **map, int i)
{
	size_t		j;

	j = 0;
	while (map[i][j])
	{
		if (map[i][j] == '1' || map[i][j] == ' ')
			j++;
		else
			return (1);
	}
	return (0);
}

static int		check_in_cycle(char **map, int i)
{
	size_t		j;

	j = 0;
	while (j < ft_strlen(map[i]))
	{
		if (check_cell(map, map[i][j], i, j))
			return (1);
		j++;
	}
	return (0);
}

static int		validator_map(char **map)
{
	int		i;
	size_t	j;

	i = 1;
	if (check_bot_top(map, 0))
		return (1);
	while (map[i + 1])
	{
		if (map[i][0] != ' ' && map[i][0] != '1')
			return (1);
		if (map[i][ft_strlen(map[i]) - 1] != ' ' \
			&& map[i][ft_strlen(map[i]) - 1] != '1')
			return (1);
		j = 0;
		if (check_in_cycle(map, i))
			return (1);
		i++;
	}
	if (check_bot_top(map, i))
		return (1);
	return (0);
}

void			analyze_map(char **map)
{
	if (validator_map(map))
		bad_config_exit();
}
