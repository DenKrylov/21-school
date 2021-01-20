/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_dip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 13:49:54 by monie             #+#    #+#             */
/*   Updated: 2020/07/31 17:07:23 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_di_util(int minus, int space, t_parser *box)
{
	if (box->zero && minus)
		ft_putchar('-', box);
	if (box->minus == 0)
		ft_put_spaces_or_zero(space, box);
	if (!box->zero && minus)
		ft_putchar('-', box);
}

void	ft_put_di(int n, t_parser *box)
{
	int	len;
	int	minus;
	int	p_zero;
	int	space;

	minus = 0;
	if (n < 0)
	{
		n *= -1;
		minus = 1;
	}
	len = ft_get_u_len(n);
	if (n == 0 && box->precision == 0)
		len = 0;
	p_zero = box->precision - len;
	if (p_zero > 0)
		space = box->width - minus - box->precision;
	else
		space = box->width - minus - len;
	ft_put_di_util(minus, space, box);
	ft_put_zeros(p_zero, box);
	if (len != 0)
		ft_put_u(n, box);
	if (box->minus == 1)
		ft_put_spaces_or_zero(space, box);
}

void	ft_put_p(void *p, t_parser *box)
{
	ssize_t	addres;
	int		space;

	addres = *(ssize_t*)&p;
	if (addres == 0)
		space = box->width - 3;
	else
		space = box->width - 11;
	if (box->minus == 0)
		ft_put_spaces_or_zero(space, box);
	ft_putchar('0', box);
	ft_putchar('x', box);
	ft_hex(addres, 0, box);
	if (box->minus == 1)
		ft_put_spaces_or_zero(space, box);
}
