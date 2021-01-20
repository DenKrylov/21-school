/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_sz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:26:16 by monie             #+#    #+#             */
/*   Updated: 2020/07/31 17:07:25 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_spaces_or_zero(int i, t_parser *box)
{
	if (box->zero == 0 || (box->zero == 1 && box->minus == 1))
	{
		while (i > 0)
		{
			ft_putchar(' ', box);
			i--;
		}
	}
	else if (box->zero == 1)
	{
		while (i > 0)
		{
			ft_putchar('0', box);
			i--;
		}
	}
}

void	ft_put_zeros(int i, t_parser *box)
{
	while (i > 0)
	{
		ft_putchar('0', box);
		i--;
	}
}
