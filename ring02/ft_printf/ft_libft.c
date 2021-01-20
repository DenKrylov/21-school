/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 12:25:17 by monie             #+#    #+#             */
/*   Updated: 2020/07/31 17:10:53 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *nptr)
{
	int new_s;
	int negative;

	new_s = 0;
	negative = 1;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t' ||
		*nptr == '\v' || *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '-')
		negative = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= 48 && *nptr <= 57)
	{
		new_s = new_s * 10 + (*nptr - 48);
		nptr++;
	}
	new_s = new_s * negative;
	return (new_s);
}

void	ft_putstr(char *str, t_parser *box)
{
	int len;
	int space;

	len = ft_strlen(str);
	if (box->precision > len || box->precision == -1)
	{
		box->precision = len;
	}
	space = box->width - box->precision;
	if (box->minus == 0)
	{
		ft_put_spaces_or_zero(space, box);
		ft_print_str(str, box);
	}
	else if (box->minus == 1)
	{
		ft_print_str(str, box);
		ft_put_spaces_or_zero(space, box);
	}
}

char	*ft_strchr(const char *s, int c)
{
	char	*new_s;

	new_s = (char *)s;
	while (*new_s != c)
	{
		if (*new_s == '\0')
		{
			return (NULL);
		}
		new_s++;
	}
	return (new_s);
}

size_t	ft_strlen(const char *s)
{
	unsigned char	*new_s;
	size_t			i;

	new_s = (unsigned char *)s;
	i = 0;
	while (new_s[i] != '\0')
		i++;
	return (i);
}

void	ft_putnbr(int n, int fd, t_parser *box)
{
	const int base = 10;

	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', box);
		n = -n;
	}
	if (n < base)
		ft_putchar(n + '0', box);
	if (n >= base)
	{
		ft_putnbr(n / base, fd, box);
		ft_putchar(n % base + '0', box);
	}
}
