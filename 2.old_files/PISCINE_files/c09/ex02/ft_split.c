/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:11:40 by rteles            #+#    #+#             */
/*   Updated: 2025/04/03 14:34:37 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	checkcharset(char letter, char *charset)
{
	int	a;

	a = 0;
	while (charset[a] != letter && charset[a] != '\0')
		a++;
	if (charset[a] == letter)
		return (1);
	else
		return (0);
}

int	countwords(char *str, char *charset)
{
	int	i;
	int	words;
	int	t;

	i = 0;
	words = 0;
	if (charset == 0)
		return (1);
	while (str[i])
	{
		while (checkcharset(str[i], charset) == 1 && str[i] != 0)
			i++;
		if (checkcharset(str[i], charset) == 0 && str[i] && t != 1)
		{
			words++;
			while (checkcharset(str[i], charset) == 0 && str[i])
				i++;
		}
		else if (str[i])
			i++;
		t = 0;
	}
	return (words);
}

int	copy(char *str, char *charset, int i, char **s)
{
	int		size;
	int		pos;

	size = 0;
	while (checkcharset(str[i], charset) == 0 && str[i])
	{
		size++;
		i++;
	}
	pos = i;
	*s = malloc((size + 1) * sizeof(char));
	if (*s == 0)
		return (0);
	(*s)[size] = '\0';
	while (size > 0)
	{
		(*s)[size - 1] = str[i - 1];
		size--;
		i--;
	}
	return (pos);
}

char	**ft_split(char *str, char *charset)
{
	int		size;
	char	**s;
	int		i;
	int		a;

	if (str == 0)
		return (0);
	size = countwords(str, charset);
	s = malloc((size + 1) * sizeof(char *));
	if (s == 0)
		return (0);
	i = 0;
	a = 0;
	while (a < size && str[i])
	{
		while (checkcharset(str[i], charset) == 1 && str[i])
			i++;
		if (checkcharset(str[i], charset) == 0 && str[i])
			i = copy(str, charset, i, &s[a]);
		a++;
	}
	s[size] = NULL;
	return (s);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	**split_string;

// 	split_string = ft_split("hello.I.am,Felix.Tan", ",.");
// 	printf("%s %s %s %s", split_string[0], split_string[1], split_string[2],
// 		split_string[3]);
// 	free(split_string);
// 	return (0);
// }
// // is the free right?? not sure
