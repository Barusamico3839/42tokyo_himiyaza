# Makefile for building a simple C project

SRC = main.c
OBJ = $(SRC:.c=.o)

all:	$(OBJ) ../minilibx-linux/libmlx_Linux.a
	gcc -Wall -Werror -Wextra -Iminilibx-linux -o so_long.out main.c \
	../minilibx-linux/libmlx_Linux.a -lX11 -lXext -lXpm

clean:
	rm -f $(OBJ) 
	
fclean:
	rm -f so_long.out
	rm -f $(OBJ)