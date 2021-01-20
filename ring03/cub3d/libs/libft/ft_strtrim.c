/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 23:26:05 by monie             #+#    #+#             */
/*   Updated: 2020/10/27 23:07:04 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, const char *set)
{
	size_t			index;

	index = 0;
	while (index < ft_strlen(set))
	{
		if (c == set[index])
			return (1);
		index++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, const char *set)
{
	size_t			index1;
	size_t			index2;
	char			*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	index1 = 0;
	while (ft_isset(s1[index1], set) && s1)
		index1++;
	if (s1[index1] == '\0')
	{
		if (!(str = (char *)malloc(sizeof(char))))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	index2 = ft_strlen(s1) - 1;
	while (ft_isset(s1[index2], set) && s1)
		index2--;
	if (!(str = (char *)malloc(sizeof(char) * (index2 - index1 + 2))))
		return (NULL);
	ft_strlcpy(str, &(s1[index1]), index2 - index1 + 2);
	return (str);
}
