/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:49:25 by himiyaza          #+#    #+#             */
/*   Updated: 2025/05/05 19:35:21 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 文字列 `s` を文字 `c` で区切り、分割された文字列を格納した配列を返す関数。
static void	free_all(char **result, size_t i)
{
	while (i > 0)
		free(result[--i]);
	free(result);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	num_of_words;

	num_of_words = 0;
	i = 0;
	while (s[i])
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			num_of_words++;
		i++;
	}
	return (num_of_words);
}

static char	**split_words(char const *s, char c, char **result)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		result[j] = ft_substr(s, start, i - start);
		if (!result[j])
		{
			free_all(result, j);
			return (NULL);
		}
		j++;
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	num_of_words;

	if (!s)
		return (NULL);
	num_of_words = count_words(s, c);
	result = (char **)ft_calloc(num_of_words + 1, sizeof(char *));
	if (result == NULL)
		return (NULL);
	return (split_words(s, c, result));
}
