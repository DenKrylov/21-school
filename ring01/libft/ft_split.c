/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 16:32:48 by monie             #+#    #+#             */
/*   Updated: 2020/05/27 11:37:47 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_split_len(char const *s, char c)
{
	size_t i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

static	size_t	ft_split_num(char const *s, char c)
{
	int i;

	i = 0;
	if (*s == c)
		i = -1;
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1) != '\0')
			i++;
		s++;
	}
	if (i == -1)
		return (0);
	return (i);
}

static	char	**ft_split_it(char const *s, char c)
{
	int		len;
	int		i;
	char	**new_s;

	if (!(new_s = (char**)malloc(sizeof(char*) * (ft_split_num(s, c) + 2))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = ft_split_len(s, c);
			if (!(new_s[i] = (char*)malloc(sizeof(char) * len + 1)))
			{
				while (i-- != 0)
					free(new_s[i]);
				return (NULL);
			}
			ft_strlcpy(new_s[i++], s, len + 1);
			s = s + len - 1;
		}
		s++;
	}
	new_s[i] = 0;
	return (new_s);
}

char			**ft_split(char const *s, char c)
{
	char	**new_s;

	if (!s)
		return (NULL);
	new_s = ft_split_it(s, c);
	return (new_s);
}
