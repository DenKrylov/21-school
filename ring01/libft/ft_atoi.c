/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 23:26:05 by monie             #+#    #+#             */
/*   Updated: 2020/05/26 12:43:53 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int new_s;
	int negative;

	new_s = 0;
	negative = 1;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t' ||
		*nptr == '\v' || *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '-')
		negative = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= 48 && *nptr <= 57)
	{
		new_s = new_s * 10 + (*nptr - 48);
		nptr++;
	}
	new_s = new_s * negative;
	return (new_s);
}
