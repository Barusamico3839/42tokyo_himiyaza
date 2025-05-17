/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:54:12 by feltan            #+#    #+#             */
/*   Updated: 2025/04/02 23:21:47 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

// if str[i] is the same as charset then 1 if not 0
int	ft_strlen_sep(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && is_separator(str[i], charset) == 0)
		i++;
	return (i);
}

// measures the length till the separator
int	count_words(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (is_separator(str[i], charset) != 0)
			i++;
		if (str[i] != '\0')
		{
			count++;
			while (is_separator(str[i], charset) == 0 && str[i] != 0)
				i++;
		}
	}
	return (count);
}

// count is the number of words, i is the letter place
char	*add_word(char *str, int len)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**strings;
	int		i;
	int		j;
	int		word_len;
	int		word_count;

	i = 0;
	j = 0;
	word_count = count_words(str, charset);
	strings = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (strings == 0)
		return (0);
	while (str[i] != '\0')
	{
		while (is_separator(str[i], charset))
			i++;
		word_len = ft_strlen_sep(&str[i], charset);
		if (word_len)
			strings[j++] = add_word(&str[i], word_len);
		i += word_len;
		word_len = 0;
	}
	strings[i] = 0;
	return (strings);
}
#include <stdio.h>

int	main(void)
{
	char	**split_string;

	split_string = ft_split("heddnshshbdkajdjcoweidolc jTan", "adf");
	printf("%s %s %s %s", split_string[0], split_string[1], split_string[2],
		split_string[1]);
	free(split_string);
	return (0);
}
// is the free right ? ? not sure
