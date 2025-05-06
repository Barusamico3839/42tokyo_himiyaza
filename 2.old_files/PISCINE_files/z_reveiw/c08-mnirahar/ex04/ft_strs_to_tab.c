/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:31:46 by himiyaza          #+#    #+#             */
/*   Updated: 2025/04/02 14:06:18 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*dst;
	int		src_len;
	int		position;

	src_len = ft_strlen(src);
	dst = malloc(sizeof(*dst) * (src_len + 1));
	if (dst == 0)
		return (0);
	position = 0;
	while (src[position] != 0)
	{
		dst[position] = src[position];
		position++;
	}
	dst[position] = 0;
	return (dst);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*res;
	int			position;

	position = 0;
	res = malloc(sizeof(*res) * (ac + 1));
	if (res == 0)
		return (0);
	while (position < ac)
	{
		res[position].size = ft_strlen(av[position]);
		res[position].str = av[position];
		res[position].copy = ft_strdup(res[position].str);
		position++;
	}
	res[position].str = 0;
	return (res);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stock_str	*kouzoutai;
	int			i;

	kouzoutai = ft_strs_to_tab(argc - 1, argv + 1);
	if (kouzoutai == 0)
		return (1);
	i = 0;
	while (kouzoutai[i].str != 0)
	{
		printf("Index: %d\n", i);
		printf("Size: %d\n", kouzoutai[i].size);
		printf("Original: %s\n", kouzoutai[i].str);
		printf("Copy: %s\n", kouzoutai[i].copy);
		printf("\n");
		i++;
	}
	i = 0;
	while (kouzoutai[i].str != 0)
	{
		free(kouzoutai[i].copy);
		i++;
	}
	free(kouzoutai);
	return (0);
}
