/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 23:29:03 by monie             #+#    #+#             */
/*   Updated: 2020/05/24 18:59:17 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;

	destination = (unsigned char *)dest;
	source = (unsigned char *)src;
	if (destination == source)
		return (dest);
	else if (destination > source)
	{
		source = (unsigned char *)source + n - 1;
		destination = dest + n - 1;
		while (n--)
			*destination-- = *source--;
	}
	else if (destination < source)
	{
		while (n--)
			*destination++ = *source++;
	}
	return (dest);
}
