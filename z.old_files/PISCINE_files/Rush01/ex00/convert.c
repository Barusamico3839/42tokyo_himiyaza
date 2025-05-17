/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohmori <sohmori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:08:29 by ttanaka           #+#    #+#             */
/*   Updated: 2025/03/24 20:34:30 by sohmori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	input_to_clues(t_puzzle *t_puzzle, char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	if (len % 8 != 7)
		return (1);
	t_puzzle->size = (len + 1) / 8;
	t_puzzle->clues = (int *)malloc(sizeof(int) * (4 * t_puzzle->size));
	if (!t_puzzle->clues)
		return (-1);
	i = 0;
	while (i < len)
	{
		if ((i % 2 == 0 && (str[i] < '1' || str[i] > ('0' + t_puzzle->size)))
			|| (i % 2 == 1 && str[i] != ' '))
		{
			free(t_puzzle->clues);
			return (1);
		}
		if (i % 2 == 0)
			t_puzzle->clues[i / 2] = str[i] - '0';
		i++;
	}
	return (0);
}

char	*ft_nums_to_str(int *nums, int size)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (2 * size));
	if (!str)
	{
		ft_putstr_error("Error\nメモリの確保に失敗しました");
		return (NULL);
	}
	while (i < 2 * size - 1)
	{
		if (i % 2 == 0)
			str[i] = nums[i / 2] + '0';
		else
			str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}
