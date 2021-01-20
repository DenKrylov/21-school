# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: monie <monie@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/26 21:44:41 by monie             #+#    #+#              #
#    Updated: 2020/10/27 23:10:07 by monie            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
FLAGS = -Wall -Wextra -Werror -O2 -O3
SOURCES = main.c get_next_line.c get_next_line_utils.c parse_map.c draw.c \
			key_press.c player.c parser.c utils.c draw_utils.c \
			sprite.c draw_sprite.c screen.c clear_memory.c \
			parser_utils.c analyze_map.c
			
LIBFT = libs/libft.a
SRCS_DIR = srcs
HEADER = headers/cub3d.h

SOURCES_IN_DIR = $(addprefix $(SRCS_DIR)/, $(SOURCES))

all: $(NAME)

$(NAME): $(LIBFT) $(SOURCES_IN_DIR)
	gcc $(FLAGS) $(SOURCES_IN_DIR) -lmlx -Llibs -lft -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	cd ./libs/libft && make && make bonus
	mv ./libs/libft/libft.a libs

clean:
	cd ./libs/libft && make fclean
	rm -rf libs/libft.a

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
