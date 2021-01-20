/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 23:26:05 by monie             #+#    #+#             */
/*   Updated: 2020/10/27 23:06:27 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	index;
	size_t	size;

	index = 0;
	while (dest[index] != '\0' && index < n)
		index++;
	size = index;
	if (size == n)
		return (size + ft_strlen(src));
	while (src[index - size] && index < (n - 1))
	{
		dest[index] = src[index - size];
		index++;
	}
	if (size < n)
		dest[index] = '\0';
	return (size + ft_strlen(src));
}
