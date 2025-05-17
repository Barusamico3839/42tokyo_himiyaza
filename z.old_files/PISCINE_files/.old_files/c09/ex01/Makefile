# Variables
NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
HEADERS		= includes
LIBC		= ar rcs
LIBR		= ranlib

SRC			=	srcs/ft_putchar.c \
				srcs/ft_putstr.c \
				srcs/ft_strcmp.c \
				srcs/ft_strlen.c \
				srcs/ft_swap.c

OBJ			= $(SRC:.c=.o)

# Rules
.c.o:
	${CC} ${CFLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	${LIBC} ${NAME} ${OBJ}
	${LIBR} ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all
