NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address -g
SRC = 2.push_swap.c 3.make_list.c 4.pa_pb.c 5.sa_sb_ss.c 6.ra_rb_rr.c 7.rra_rrb_rrr.c \
		 8.coordinate_compression.c 9.bubble_sort_tekitou.c 10.push_swaps100.c \
		 11.ultimate_lis_turk100.c 12.super_swapped_lis.c 13.lis.c 13.turk.c 14.push_swaps500.c   
OBJ = $(SRC:.c=.o)
TEST_SRC = 1.main.c
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_EXE = test.out

all: 

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) $(TEST_OBJ)

fclean: clean
	rm -f $(NAME) $(TEST_EXE) a.out

re: fclean all

test: $(OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) -o $(TEST_EXE) $(TEST_OBJ) $(OBJ)
	@echo "Run ./$(TEST_EXE) to test."

.PHONY: all clean fclean re test