/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:37:26 by rteles            #+#    #+#             */
/*   Updated: 2025/04/02 01:52:27 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_total_len(int size, char **strings, char *sep)
{
	int	total;
	int	i;
	int	sep_len;

	total = 0;
	i = 0;
	sep_len = ft_strlen(sep);
	while (i < size)
	{
		total = total + ft_strlen(strings[i]) + sep_len;
		i++;
	}
	total -= sep_len;
	return (total);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_cpy_strings(char **strings, char *result, char *sep, int size)
{
	int		i;
	int		sep_len;
	char	*temp;

	i = 0;
	sep_len = ft_strlen(sep);
	temp = result;
	while (i < size)
	{
		ft_strcpy(temp, strings[i]);
		temp = temp + ft_strlen(strings[i]);
		if (i < size - 1)
		{
			ft_strcpy(temp, sep);
			temp = temp + sep_len;
		}
		i++;
	}
	temp[i] = '\0';
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*empty;
	char	*result;
	int		total_len;

	if (size == 0)
	{
		empty = malloc(1);
		if (empty != 0)
			empty[0] = '\0';
		return (empty);
	}
	total_len = ft_total_len(size, strs, sep);
	result = (char *)malloc(sizeof(char) * (total_len + 1));
	result = ft_cpy_strings(strs, result, sep, size);
	return (result);
}

int	main(void)
{
	char	*strs[] = {"one", "two", "three"};
	char	*res;

	res = ft_strjoin(2, strs, " | ");
	printf("%s", res);
	free(res);
	return (0);
}
