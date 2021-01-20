/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 23:29:29 by monie             #+#    #+#             */
/*   Updated: 2020/05/26 13:50:11 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t k;

	i = 0;
	k = 0;
	if (!*s2)
		return ((char*)s1);
	while (s1[i] && i < n)
	{
		while (s1[i + k] && s1[i + k] == s2[k] && (i + k) < n)
			k++;
		if (!s2[k])
			return ((char*)(s1 + i));
		else
			k = 0;
		i++;
	}
	return (NULL);
}
