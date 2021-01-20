/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:44:41 by monie             #+#    #+#             */
/*   Updated: 2020/10/27 23:08:43 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

static int	error_exit(char **buffer, char **line)
{
	free(*line);
	*line = NULL;
	free(*buffer);
	*buffer = NULL;
	return (ERROR);
}

static int	get_line(char **remainder, char **line, int length)
{
	int		newline_index;
	char	*ptr;

	(*remainder)[length] = '\0';
	newline_index = consists(*remainder, SYMBOL_NEW_LINE);
	if (newline_index != -1)
	{
		ptr = *line;
		if (!(*line = ft_strjoin(*line, *remainder)))
			return (error_exit(remainder, line));
		free(ptr);
		(*line)[consists(*line, SYMBOL_NEW_LINE)] = '\0';
		ptr = *remainder;
		*remainder = ft_strdup(*remainder + newline_index + 1);
		free(ptr);
		return (ENDLINE_REACHED);
	}
	ptr = *line;
	if (!(*line = ft_strjoin(*line, *remainder)))
		return (error_exit(remainder, line));
	free(ptr);
	ptr = NULL;
	return (ENDLINE_NOT_FOUND);
}

int			get_next_line(int fd, char **line)
{
	static char		*remainder = NULL;
	char			buffer_check[1];
	int				value;
	int				length;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buffer_check, 0) < 0)
		return (ERROR);
	if (!(*line = ft_strdup("")))
		return (ERROR);
	if (remainder)
		if ((value = get_line(&remainder, line, ft_strlen(remainder))) != 0)
			return (value);
	free(remainder);
	if (!(remainder = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (error_exit(&remainder, line));
	while ((length = read(fd, remainder, BUFFER_SIZE)) > 0)
		if ((value = get_line(&remainder, line, length)) != 0)
			return (value);
	free(remainder);
	remainder = NULL;
	if (length != BUFFER_SIZE)
		return (EOF_REACHED);
	return (ENDLINE_REACHED);
}
