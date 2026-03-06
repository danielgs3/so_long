# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danielg3 <danielg3@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/04 18:24:08 by danielg3          #+#    #+#              #
#    Updated: 2026/03/06 17:21:26 by danielg3         ###   ########.fr        #
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
	            src/map_checker.c \
	            src/map_checker_2.c \
	            src/map_flood.c \
	            src/render.c \
				include/get_next_line/get_next_line.c \
            	include/get_next_line/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -I$(MLX_DIR) -Iinclude -I$(LIBFT_DIR) -c $< -o $@

LIBFT_DIR = include/libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = include/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX) -lX11 -lXext -o $(NAME)
	@echo "------------\n| Done! 👌 |\n------------\n"

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)

$(FT_PRINTF):
	@$(MAKE) -sC $(FT_PRINTF_DIR)

$(MLX):
	@$(MAKE) -sC $(MLX_DIR)

all: $(NAME)

clean:
	@$(MAKE) clean -sC $(LIBFT_DIR)
	@$(MAKE) clean -sC $(FT_PRINTF_DIR)
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -sC $(LIBFT_DIR)
	@$(MAKE) fclean -sC $(FT_PRINTF_DIR)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
