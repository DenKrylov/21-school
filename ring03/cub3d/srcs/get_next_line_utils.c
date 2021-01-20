/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:44:41 by monie             #+#    #+#             */
/*   Updated: 2020/10/27 23:08:37 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

int			consists(const char *str, const char c)
{
	int		column;

	column = 0;
	while (str[column] != '\0')
	{
		if (str[column] == c)
			return (column);
		column++;
	}
	return (FALSE);
}

size_t		ft_strlen(const char *c)
{
	size_t	size;

	size = 0;
	while (c[size])
		size++;
	return (size);
}

char		*ft_strjoin(const char *s1, const char *s2)
{
	char	*to_return;
	size_t	size;
	size_t	len1;
	size_t	len2;
	size_t	index;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	index = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	size = len1 + len2;
	if (!(to_return = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (s1[index])
	{
		to_return[index] = s1[index];
		index++;
	}
	index = 0;
	while (s2[index])
		to_return[len1++] = s2[index++];
	to_return[len1] = '\0';
	return (to_return);
}

char		*ft_strdup(const char *s)
{
	char	*to_return;
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	if (!(to_return = (char *)malloc(sizeof(char) * length + 1)))
		return (NULL);
	length = 0;
	while (s[length] != '\0')
	{
		to_return[length] = s[length];
		length++;
	}
	to_return[length] = '\0';
	return (to_return);
}
