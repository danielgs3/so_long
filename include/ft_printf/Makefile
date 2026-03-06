NAME = libftprintf.a

SRC = ft_printf.c ft_puthex.c ft_puthex_upper.c ft_putptr.c ft_putnbr.c ft_putchar.c ft_putstr.c ft_putnbr_unsigned.c

CC = cc

CFLAGS = -Werror -Wextra -Wall

AR = ar rcs

RM = rm -f

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
