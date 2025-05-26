# get_next_line Makefile

# コンパイラとフラグの設定
CC = cc
CFLAGS = -Wall -Wextra -Werror

# ファイル名設定
NAME = get_next_line.a
SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)
TEST_SRC = main.c
TEST_OUT = test.out

# デフォルトのBUFFER_SIZE（コンパイル時に上書き可能）
BUFFER_SIZE ?= 4

# 標準ターゲット - ライブラリ作成
all: $(NAME)

# ライブラリ作成
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# テスト実行ファイル作成
test: $(NAME)
	$(CC) $(CFLAGS) -g -D BUFFER_SIZE=$(BUFFER_SIZE) -o $(TEST_OUT) $(TEST_SRC) get_next_line.a

# オブジェクトファイル作成
%.o: %.c
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

# クリーンアップ
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(TEST_OUT)

re: fclean all

# ボーナス部分
#BONUS_SRC = get_next_line_bonus.c
#BONUS_OBJ = $(BONUS_SRC:.c=.o)

#bonus: $(BONUS_OBJ)
#	ar rcs $(NAME) $(BONUS_OBJ)

.PHONY: all clean fclean re test bonus