NAME = get_next_line
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = get_next_line.c #get_next_line_utils.c
OBJ = $(SRC:.c=.o)
TEST_SRC = main.c
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_EXE = test_gnl

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) $(TEST_OBJ)

fclean: clean
	rm -f $(NAME) $(TEST_EXE) a.out

re: fclean all

test: $(OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) -o $(TEST_EXE) $(TEST_OBJ) $(OBJ)
	@echo "Run ./$(TEST_EXE) to test."

.PHONY: all clean fclean re test