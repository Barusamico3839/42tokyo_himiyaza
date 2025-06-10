NAME = get_next_line.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g -D BUFFER_SIZE=2147483647
SRC = get_next_line.c get_next_line_utils.c
BONUS_SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRCS:.c=.o)
TEST_SRC = main.c
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_EXE = test_gnl

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ)

clean:
	rm -f $(OBJ) $(TEST_OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(TEST_EXE) a.out

re: fclean all

test: $(OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) -o $(TEST_EXE) $(TEST_OBJ) $(OBJ)
	@echo "Run ./$(TEST_EXE) to test."

test2: $(BONUS_OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) -o test_bonus $(TEST_OBJ) $(BONUS_OBJ)
	@echo "Run test_bonus to test."

.PHONY: all clean fclean re test