/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 23:26:05 by monie             #+#    #+#             */
/*   Updated: 2020/10/27 23:06:04 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			ft_tocount(const char *s, char c)
{
	size_t			index;
	size_t			count;

	index = 0;
	count = 0;
	while (s[index])
	{
		if (s[index] != c)
		{
			count++;
			while (s[index] != c && s[index] != '\0')
				index++;
		}
		else
			index++;
	}
	return (count);
}

static char				**ft_free_str(char **str)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		free(str[index]);
		index++;
	}
	free(str);
	return (NULL);
}

static char				**ft_tofill(const char *s, char **str,
										char c, size_t count)
{
	size_t			index1;
	size_t			index2;

	index1 = 0;
	while (index1 < count && *s)
	{
		index2 = 0;
		if (*s != c)
		{
			while (*s != c && *s)
			{
				index2++;
				s++;
			}
			if (!(str[index1] = (char *)malloc(sizeof(char) * (index2 + 1))))
				return (ft_free_str(str));
			str[index1] = ft_memcpy(str[index1], s - index2, index2);
			str[index1][index2] = '\0';
			index1++;
		}
		while (*s == c && *s)
			s++;
	}
	str[index1] = NULL;
	return (str);
}

char					**ft_split(const char *s, char c)
{
	char			**str;
	size_t			count;

	str = NULL;
	if (!s)
		return (NULL);
	count = ft_tocount(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	if (!(ft_tofill(s, str, c, count)))
		return (NULL);
	return (str);
}
