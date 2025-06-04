/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:37:47 by takawagu          #+#    #+#             */
/*   Updated: 2025/06/04 22:06:25 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*copy;

	len = ft_strlen(s);
	copy = my_malloc(len + 1);
	if (copy == NULL)
		return ((NULL));
	i = 0;
	while (i < len)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	res = my_malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!res)
		return (NULL);
	tmp = res;
	while (*s1)
		*tmp++ = *s1++;
	while (*s2)
		*tmp++ = *s2++;
	*tmp = '\0';
	return (res);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if ((dst == NULL && src == NULL) || n == 0)
		return (dst);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void	*my_malloc(size_t size)
{
	// void *ptr = malloc(size);
	// return (ptr);
	int r;
	
	r = rand() % 10; // 0〜9のランダムな整数
	if (r == 0)      // 10%の確率（0だけ）
	{
		printf("❌ malloc failed intentionally!\n");
		return (NULL);
	}
	else
	{
		void *ptr = malloc(size);
		if (ptr != NULL)
			printf("✅ malloc succeeded (%zu bytes)\n", size);
		else
			printf("💀 malloc failed naturally\n");
		return (ptr);
	}
}