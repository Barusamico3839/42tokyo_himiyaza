CC      := gcc
CFLAGS  := -Wall -Werror -Wextra -no-pie -g -fsanitize=address
INCLUDES:= -Iminilibx-linux -I1.srcs/get_next_line -I1.srcs/printf

SRC     := 1.srcs/functions/main.c \
           1.srcs/functions/1.nakami.c \
           1.srcs/functions/2.timer.c \
           1.srcs/get_next_line/get_next_line.c \
           1.srcs/get_next_line/get_next_line_utils.c \
			1.srcs/printf/ft_printf.c \
			1.srcs/printf/ft_printf_utils.c \
			
OBJ     := $(SRC:.c=.o)

MLX_DIR := 1.srcs/minilibx-linux
MLX_LIB := $(MLX_DIR)/libmlx_Linux.a

NAME    := so_long

all: $(NAME)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ) $(MLX_LIB)
	xset -r
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJ) $(MLX_LIB) -lX11 -lXext
	@echo "Run ./$(NAME) to test."

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	xset r
	rm -f $(NAME)

re: fclean all
	xset -r

.PHONY: all clean fclean