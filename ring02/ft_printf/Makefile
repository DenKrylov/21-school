# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: monie <monie@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/31 13:18:43 by monie             #+#    #+#              #
#    Updated: 2020/07/31 17:46:29 by monie            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =  ft_get_len.c ft_libft.c ft_parser.c ft_printf.c ft_printf_additions.c ft_printf_write.c ft_put_cs.c ft_put_dip.c ft_put_sz.c ft_put_ux.c 

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I ./

OFILES = $(SRCS:.c=.o)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OFILES)

all : $(NAME)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all
