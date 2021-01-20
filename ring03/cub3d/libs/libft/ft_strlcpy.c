/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 23:26:05 by monie             #+#    #+#             */
/*   Updated: 2020/10/27 23:06:33 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t size;

	if (src == NULL)
		return (0);
	if (n == 0)
		return (ft_strlen(src));
	size = 0;
	while (size < (n - 1) && src[size] != '\0')
	{
		dest[size] = src[size];
		size++;
	}
	if (n > 0)
		dest[size] = '\0';
	return (ft_strlen(src));
}
