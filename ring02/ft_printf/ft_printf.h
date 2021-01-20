/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monie <monie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 19:35:39 by monie             #+#    #+#             */
/*   Updated: 2020/07/31 17:12:08 by monie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef	struct	s_parser
{
	int	width;
	int	minus;
	int	precision;
	int	dot;
	int	w_asterisk;
	int	p_asterisk;
	int	zero;
	int	count;
}				t_parser;

int				ft_printf(const	char *conversions, ...);
void			ft_putchar_fd(char c, int fd);
void			init_parser(t_parser *box);
void			print_parser(t_parser *box);
void			ft_putchar(char c, t_parser *box);
size_t			ft_strlen(const char *s);
int				ft_get_x_len(unsigned int dec);
int				ft_get_u_len(unsigned int dec);
void			ft_put_spaces_or_zero(int i, t_parser *box);
void			ft_precision(char *str, t_parser *box);
void			ft_putstr(char *str, t_parser *box);
void			ft_hex(ssize_t digit, int i, t_parser *box);
void			ft_put_x(unsigned int dec, int i, t_parser *box);
void			ft_put_u(unsigned int dec, t_parser *box);
void			ft_put_p(void *p, t_parser *box);
void			ft_put_di(int n, t_parser *box);
void			ft_put_c(char c, t_parser *box);
void			ft_print_u(unsigned int dec, t_parser *box);
void			ft_put_zeros(int i, t_parser *box);
int				ft_atoi(const char *nptr);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
char			*ft_strchr(const char *s, int c);
void			ft_print_str(char *str, t_parser *box);
void			check_box(va_list ap, t_parser *box);
void			printout(char c, va_list ap, t_parser *box);
void			while_loop(va_list ap, const char *conversions, t_parser *box);
int				ft_process_wp(int i, const char *conversions, t_parser *box);
int				ft_while(int i, const char *conversions, char *sim,\
				t_parser *box);

#endif
