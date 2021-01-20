/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 18:15:05 by monie             #+#    #+#             */
/*   Updated: 2020/05/23 18:33:56 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*new_nmemb;
	size_t	i;

	i = 0;
	if (!(new_nmemb = (char*)malloc(nmemb * size)))
		return (NULL);
	while (i < nmemb * size)
	{
		new_nmemb[i] = 0;
		i++;
	}
	return (new_nmemb);
}
