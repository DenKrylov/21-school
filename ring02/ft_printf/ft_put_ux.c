/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 13:46:38 by monie             #+#    #+#             */
/*   Updated: 2020/07/31 17:07:26 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex(ssize_t digit, int i, t_parser *box)
{
	char *x;

	if (i)
		x = "0123456789ABCDEF";
	else
		x = "0123456789abcdef";
	if (digit > 15)
		ft_hex(digit / 16, i, box);
	ft_putchar(x[digit % 16], box);
}

void	ft_put_x(unsigned int hex, int i, t_parser *box)
{
	int len;
	int p_zero;
	int space;

	len = ft_get_x_len(hex);
	if (hex == 0 && box->precision == 0)
		len = 0;
	p_zero = box->precision - len;
	if (p_zero > 0)
		space = box->width - box->precision;
	else
		space = box->width - len;
	if (box->minus == 0)
		ft_put_spaces_or_zero(space, box);
	ft_put_zeros(p_zero, box);
	if (len != 0)
		ft_hex(hex, i, box);
	if (box->minus == 1)
		ft_put_spaces_or_zero(space, box);
}

void	ft_put_u(unsigned int dec, t_parser *box)
{
	int len;
	int base;
	int digit;

	base = 1;
	len = ft_get_u_len(dec);
	while (--len > 0)
	{
		base *= 10;
	}
	while (base > 0)
	{
		digit = dec / base;
		dec %= base;
		base /= 10;
		ft_putchar(digit + '0', box);
	}
}

void	ft_print_u(unsigned int dec, t_parser *box)
{
	int len;
	int p_zero;
	int space;

	len = ft_get_u_len(dec);
	if (dec == 0 && box->precision == 0)
		len = 0;
	p_zero = box->precision - len;
	if (p_zero > 0)
		space = box->width - box->precision;
	else
		space = box->width - len;
	if (box->minus == 0)
		ft_put_spaces_or_zero(space, box);
	ft_put_zeros(p_zero, box);
	if (len != 0)
		ft_put_u(dec, box);
	if (box->minus == 1)
		ft_put_spaces_or_zero(space, box);
}
