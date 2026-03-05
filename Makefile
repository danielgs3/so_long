# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/04 18:24:08 by danielg3          #+#    #+#              #
#    Updated: 2026/03/05 13:25:15 by danielg3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

RM = rm -rf

SRCS =			src/main.c \
	            src/game.c \
	            src/events.c \
	            src/map.c \
	            src/render.c \
				include/get_next_line/get_next_line.c \
            	include/get_next_line/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

%.o: %.c
    @$(CC) $(CFLAGS) -I$(MLX_DIR) -Iinclude -I$(LIBFT_DIR) -c $< -o $@

LIBFT_DIR = include/libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -lX11 -lXext -o $(NAME)
	@echo "------------\n| Done! 👌 |\n------------\n"

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -sC $(MLX_DIR)

all: $(NAME)

clean:
	@$(MAKE) clean -sC $(LIBFT_DIR)
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -sC $(LIBFT_DIR)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
