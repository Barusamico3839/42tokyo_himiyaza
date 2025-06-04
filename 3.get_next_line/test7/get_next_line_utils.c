/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:59:21 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/03 19:12:47 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(char *whole, int to_find)
{
	int	i;

	i = 0;
	while (whole[i] != '\0')
	{
		if (whole[i] == (char)to_find)
			return (&whole[i]);
		i++;
	}
	if ((char)to_find == '\0')
		return (&whole[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*duped_str;
	size_t	i;

	i = 0;
	duped_str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (duped_str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		duped_str[i] = s[i];
		i++;
	}
	duped_str[i] = '\0';
	return (duped_str);
}

//　文字列ｓのstart番目からlen分コピーして出力する。
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*substring;

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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined_str;
	size_t	i;
	size_t	len1;
	size_t	len2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined_str = malloc((len1 + len2 + 1) * sizeof(char));
	if (joined_str == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
	{
		joined_str[i] = s1[i];
	}
	i = 0;
	while (s2[i] != '\0')
	{
		joined_str[len1 + i] = s2[i];
		i++;
	}
	joined_str[len1 + len2] = '\0';
	return (joined_str);
}
