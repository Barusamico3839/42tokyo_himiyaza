/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:34:03 by himiyaza          #+#    #+#             */
/*   Updated: 2025/04/27 13:34:31 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}
static char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;

	dup = (char *)malloc(n + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
static char	**ft_free_split(char **split, int j)
{
	while (j >= 0)
	{
		free(split[j]);
		j--;
	}
	free(split);
	return (NULL);
}
char	**ft_split(const char *s, char c)
{
	char	**split;
	int		i;
	int		j;
	int		word_len;

	if (!s)
		return (NULL);
	split = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			word_len = 0;
			while (s[i + word_len] && s[i + word_len] != c)
				word_len++;
			split[j] = ft_strndup(&s[i], word_len);
			if (!split[j])
				return (ft_free_split(split, j));
			j++;
			i += word_len;
		}
		else
			i++;
	}
	split[j] = NULL;
	return (split);
}

