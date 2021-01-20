/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 17:02:58 by monie             #+#    #+#             */
/*   Updated: 2020/05/24 20:09:10 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (!dest)
		return (0);
	while (src[k] != '\0')
		k++;
	if (!n)
		return (k);
	while (src[i] && n > (i + 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (k);
}
