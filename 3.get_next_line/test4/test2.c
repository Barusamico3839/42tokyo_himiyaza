/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:44:20 by himiyaza          #+#    #+#             */
/*   Updated: 2025/05/16 20:57:50 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h> //malloc

// 文字数数える。１から。
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// s1をduplicateして、戻り値に新しい文字列のポインタを返す。
char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	i;

	dup = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

//　文字列ｓのstart番目からlen分コピーして出力する。
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	s_len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substring = (char *)malloc((len + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	substring[len] = '\0';
	i = 0;
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	return (substring);
}

// ファイルディスクリプタから1行ずつテキストを読み込む
char *get_next_line(int fd)
{
	char *buffer;
	char *str;
	char *str2;
	int error_check;
	int flag;
	static size_t i;


	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if(buffer = NULL)
		return(NULL);
	i=0;
	while(flag = 0)
	{
		error_check = read(fd, &buffer[i] , BUFFER_SIZE);
		if(error_check = -1)
			{
				free(buffer);
				return(NULL);
			}
		while(i < error_check)
		{
			if(buffer[i] == '\n' || buffer[i] == '\0')
			{
				buffer = ft_substr(buffer, 0, i);
				flag = 1;
			}
			i++;
		}
		str += i;
		str= malloc(ft_strlen(buffer) * sizeof(char));
		str = ft_strjoin(str , buffer);
		free(buffer);
	}
}
int main (void)
{
	int fd;

    fd = open("test.txt");
    if (fd < 0) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    get_next_line(fd);

    close(fd);
    return (1);
}
