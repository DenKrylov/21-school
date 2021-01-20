/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_cs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 13:43:38 by monie             #+#    #+#             */
/*   Updated: 2020/07/31 17:07:21 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_c(char c, t_parser *box)
{
	int	space;

	space = box->width - 1;
	if (box->minus == 0)
	{
		ft_put_spaces_or_zero(space, box);
		ft_putchar(c, box);
	}
	else
	{
		ft_putchar(c, box);
		ft_put_spaces_or_zero(space, box);
	}
}
