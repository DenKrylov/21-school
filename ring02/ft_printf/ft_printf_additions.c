/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_additions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 16:08:04 by monie             #+#    #+#             */
/*   Updated: 2020/07/31 17:10:36 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_box(va_list ap, t_parser *box)
{
	if (box->w_asterisk == 1)
	{
		box->width = va_arg(ap, int);
		if (box->width < 0)
		{
			box->width *= -1;
			box->minus = 1;
		}
	}
	if (box->dot == 1 && box->precision == -1)
		box->precision = 0;
	if (box->p_asterisk == 1)
	{
		box->precision = va_arg(ap, int);
		if (box->precision < 0)
			box->precision = -1;
	}
	if (box->precision != -1)
		box->zero = 0;
}

void	printout(char c, va_list ap, t_parser *box)
{
	char		*input_null;

	if (c == '%')
		ft_put_c('%', box);
	else if (c == 's')
	{
		input_null = va_arg(ap, char *);
		if (input_null == NULL)
			ft_putstr("(null)", box);
		else
			ft_putstr(input_null, box);
	}
	else if (c == 'c')
		ft_put_c(va_arg(ap, int), box);
	else if (c == 'u')
		ft_print_u(va_arg(ap, unsigned int), box);
	else if (c == 'x')
		ft_put_x(va_arg(ap, unsigned int), 0, box);
	else if (c == 'X')
		ft_put_x(va_arg(ap, unsigned int), 1, box);
	else if (c == 'p')
		ft_put_p(va_arg(ap, void *), box);
	else if (c == 'd' || c == 'i')
		ft_put_di(va_arg(ap, int), box);
}

void	while_loop(va_list ap, const char *conversions, t_parser *box)
{
	int		i;
	char	*sim;

	sim = "%scuxXpdi";
	i = 0;
	while (conversions[i])
	{
		if (conversions[i] == '%')
		{
			i++;
			init_parser(box);
			i = ft_while(i, conversions, sim, box);
			check_box(ap, box);
			printout(conversions[i], ap, box);
		}
		else
			ft_putchar(conversions[i], box);
		i++;
	}
}

int		ft_process_wp(int i, const char *conversions, t_parser *box)
{
	if (box->dot == 0)
	{
		box->width = ft_atoi(conversions + i);
		i += ft_get_u_len(box->width) - 1;
	}
	else
	{
		box->precision = ft_atoi(conversions + i);
		i += ft_get_u_len(box->precision) - 1;
	}
	return (i);
}

int		ft_while(int i, const char *conversions, char *sim, t_parser *box)
{
	while (!ft_strchr(sim, conversions[i]))
	{
		if (conversions[i] == '-')
			box->minus = 1;
		else if (conversions[i] == '.')
			box->dot = 1;
		else if (conversions[i] == '*')
		{
			if (box->dot == 1)
				box->p_asterisk = 1;
			else
				box->w_asterisk = 1;
		}
		else if (conversions[i] == '0')
		{
			if (box->dot == 0)
				box->zero = 1;
		}
		else
			i = ft_process_wp(i, conversions, box);
		i++;
	}
	return (i);
}
