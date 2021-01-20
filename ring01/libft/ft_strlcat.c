/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 14:53:40 by monie             #+#    #+#             */
/*   Updated: 2020/05/25 13:25:11 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	destination;
	size_t	source;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	destination = ft_strlen(dst);
	source = ft_strlen(src);
	if (size < destination + 1)
		return (source + size);
	while (dst[i] && (i < size - 1))
		i++;
	while (src[k] && (i < size - 1))
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (destination + source);
}
