# ライブラリ名
NAME = libft.a

# コンパイラとフラグの設定
CC = cc
CFLAGS = -Wall -Wextra -Werror

# アーカイブコマンド
AR = ar rcs
RM = rm -f

# ソースファイル
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	  ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	  ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	  ft_atoi.c ft_calloc.c ft_strdup.c \
	  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	  ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c

# オブジェクトファイル
OBJ = $(SRC:.c=.o)

# ボーナス用ソース
BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c

# ボーナス用オブジェクト
BONUS_OBJ = $(BONUS_SRC:.c=.o)

# ルール
.PHONY: all clean fclean re bonus

all: $(NAME)

# C ファイルをコンパイル
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ライブラリの作成
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

# ボーナスパート
bonus: $(BONUS_OBJ)
	$(AR) $(NAME) $(BONUS_OBJ)

# オブジェクトファイルの削除
clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

# ライブラリと全オブジェクトファイルの削除
fclean: clean
	$(RM) $(NAME)

# 完全に再ビルド
re: fclean all
