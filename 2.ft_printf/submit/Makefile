# Makefile for ft_printf project

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft #-std=c99 -pedantic
NAME = libftprintf.a
SRC = ft_printf.c #src/ft_printf_utils.c main.c
# BONUS_SRC = src/bonus/ft_printf_bonus.c src/bonus/ft_printf_utils_bonus.c
OBJ = $(SRC:.c=.o)
# BONUS_OBJ = $(BONUS_SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = libft/libft.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $@
	ar rcs $@ $(OBJ)

# bonus: $(OBJ) $(BONUS_OBJ)
# 	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

test: all
	$(CC) $(CFLAGS) -o test.out main.c $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
