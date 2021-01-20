/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 23:50:08 by monie             #+#    #+#             */
/*   Updated: 2020/05/24 17:00:48 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_itoa_value(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int		ft_itoa_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*new_n;
	int		len;

	len = ft_itoa_len(n);
	if (!(new_n = (char*)malloc(len + 1)))
		return (NULL);
	new_n[len] = '\0';
	if (n < 0)
		new_n[0] = '-';
	else if (n == 0)
		new_n[0] = '0';
	while (n != 0)
	{
		len--;
		new_n[len] = ft_itoa_value(n % 10) + '0';
		n = n / 10;
	}
	return (new_n);
}
