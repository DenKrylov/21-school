/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 13:39:59 by monie             #+#    #+#             */
/*   Updated: 2020/07/31 17:07:20 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}

void	ft_putchar(char c, t_parser *box)
{
	write(1, &c, 1);
	box->count += 1;
}

void	ft_print_str(char *str, t_parser *box)
{
	while (str && box->precision--)
	{
		ft_putchar(*str, box);
		str++;
	}
}
