#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

// ユーティリティ関数の宣言 (staticキーワードを削除)
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);

// メイン関数
char		*get_next_line(int fd);

typedef struct gnl_kouzoutai
{
	char	*joined_str;
}			gnl_list;

#endif