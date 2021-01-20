/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:27:46 by monie             #+#    #+#             */
/*   Updated: 2020/07/31 17:07:11 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_x_len(unsigned int dec)
{
	int	i;

	i = 0;
	if (dec == 0)
		i++;
	while (dec > 0)
	{
		dec /= 16;
		i++;
	}
	return (i);
}

int	ft_get_u_len(unsigned int dec)
{
	int	i;

	i = 0;
	if (dec == 0)
		i++;
	while (dec > 0)
	{
		dec /= 10;
		i++;
	}
	return (i);
}
