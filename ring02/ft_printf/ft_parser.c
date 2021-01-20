/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 18:26:45 by monie             #+#    #+#             */
/*   Updated: 2020/07/31 17:07:12 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_parser(t_parser *box)
{
	box->width = -1;
	box->minus = 0;
	box->precision = -1;
	box->dot = 0;
	box->w_asterisk = 0;
	box->p_asterisk = 0;
	box->zero = 0;
}
