/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 19:35:01 by monie             #+#    #+#             */
/*   Updated: 2020/07/31 17:07:14 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *conversions, ...)
{
	va_list		ap;
	t_parser	*box;
	int			tmp_count;

	va_start(ap, conversions);
	box = (t_parser*)malloc(sizeof(t_parser));
	if (box == NULL)
		return (-1);
	box->count = 0;
	while_loop(ap, conversions, box);
	tmp_count = box->count;
	free(box);
	box = NULL;
	va_end(ap);
	return (tmp_count);
}
