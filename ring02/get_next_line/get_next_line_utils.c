/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 18:57:57 by monie             #+#    #+#             */
/*   Updated: 2020/07/25 13:14:30 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *str, size_t n)
{
	char	*res;
	char	*check_mem;

	check_mem = malloc(n * sizeof(char) + 1);
	if (!(check_mem))
		return (NULL);
	res = check_mem;
	while (n-- > 0)
	{
		*check_mem++ = *(char*)str++;
	}
	*check_mem = '\0';
	return (res);
}

size_t	ft_strlen(const char *s)
{
	unsigned char	*new_s;
	size_t			i;

	new_s = (unsigned char *)s;
	i = 0;
	while (new_s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(new_s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		new_s[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		new_s[i] = s2[k];
		i++;
		k++;
	}
	new_s[i] = '\0';
	return (new_s);
}

char	*ft_strchr(const char *s, int c)
{
	char			*new_s;

	new_s = (char *)s;
	while (*new_s != c)
	{
		if (*new_s == '\0')
		{
			return (NULL);
		}
		new_s++;
	}
	return (new_s);
}
