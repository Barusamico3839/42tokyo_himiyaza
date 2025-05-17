/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:02:22 by lquehec           #+#    #+#             */
/*   Updated: 2025/04/03 20:35:44 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	ft_check_map_line_len(char **array_map)
{
	int	i;
	int	j;
	int	line_len;
	int	diff_len;

	i = 0;
	j = 0;
	line_len = 0;
	diff_len = 0;
	array_map++;
	while (array_map[i])
	{
		j = ft_strprintable_len(array_map[i]);
		if (line_len != j)
			diff_len++;
		line_len = j;
		j = 0;
		i++;
	}
	if (diff_len > 1)
		return (0);
	return (1);
}
// マップの**「横幅がバラバラじゃないか」**をチェックする関数
int	ft_check_map_line_value(char **array_map, t_map map)
{
	int	i;
	int	j;
	int	line_count;

	i = 0;
	j = 0;
	line_count = ft_atoi(array_map[0]);// mapの行数を測る
	array_map++; // arrayの２行目以降を見る
	while (array_map[i])
	{
		while (ft_is_printable(array_map[i][j]))
		{
			if ((array_map[i][j] != map.empty && array_map[i][j] != map.obs))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	if (line_count != i)
		return (0);
	return (1);
}
//「マップの中身が正しい記号（map.empty または map.obs）だけでできていて、行数も指定どおりか？」をチェックする。

int	ft_is_map_valid(char **array_map, t_map map)
{
	if (!ft_check_map_line_len(array_map)
		|| !ft_check_map_line_value(array_map, map))
		return (0);
	return (1);
}
// map が正しい形式だったら１，正しくなかったら０
