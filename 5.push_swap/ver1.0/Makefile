# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/03 00:00:00 by himiyaza          #+#    #+#              #
#    Updated: 2025/07/03 01:02:56 by himiyaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = push_swap

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = 1.main.c \
       2.push_swap.c \
       3.make_list.c \
       4.pa_pb.c \
       5.sa_sb_ss.c \
       6.ra_rb_rr.c \
       7.rra_rrb_rrr.c \
       8.coordinate_compression.c \
       9.bubble_sort_tekitou.c \
       10.push_swaps100.c \
       11.ultimate_lis_turk100.c \
       12.super_swapped_lis.c \
       13.turk.c \
       14.push_swaps500.c \
	   12.5.super_swapped_lis.c

# Object files
OBJS = $(SRCS:.c=.o)

# Header file
HEADER = push_swap.h

# Default target
all: $(NAME)

# Build the main program
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Compile source files to object files
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@	

# Clean object files
clean:
	rm -f $(OBJS)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re