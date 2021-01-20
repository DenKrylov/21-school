# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: monie <monie@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/12 19:11:42 by monie             #+#    #+#              #
#    Updated: 2020/11/19 16:17:21 by monie            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

FLAG = -Wall -Werror -Wextra

SRC = ft_strlen.s ft_write.s ft_read.s ft_strcmp.s ft_strcpy.s ft_strdup.s

OBJ = $(SRC:%.s=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.s
	nasm -f macho64 $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) test text.txt

re: fclean all

test: $(NAME)
	gcc $(FLAG) -L. -lasm -o test main.c
	./test < Makefile

.PHONY: all clean fclean re test