# Makefile for ft_printf project

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = src/ft_printf.c src/ft_printf_utils.c
BONUS_SRC = src/bonus/ft_printf_bonus.c src/bonus/ft_printf_utils_bonus.c
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re