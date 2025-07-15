/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11.copy_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:55:40 by himiyaza          #+#    #+#             */
/*   Updated: 2025/07/01 04:09:12 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static char	*copy_map_row(char *src_row)
{
	char	*row_copy;
	int		len;
	int		x;

	len = 0;
	while (src_row[len] && src_row[len] != '\n')
		len++;
	row_copy = malloc(sizeof(char) * (len + 1));
	if (!row_copy)
		return (NULL);
	x = 0;
	while (x < len)
	{
		row_copy[x] = src_row[x];
		x++;
	}
	row_copy[len] = '\0';
	return (row_copy);
}

char	**copy_map(t_map *map)
{
	char	**map_copy;
	int		y;

	map_copy = malloc(sizeof(char *) * map->height);
	if (!map_copy)
		return (NULL);
	y = 0;
	while (y < map->height)
	{
		map_copy[y] = copy_map_row(map->g_map[y]);
		if (!map_copy[y])
		{
			while (--y >= 0)
				free(map_copy[y]);
			free(map_copy);
			return (NULL);
		}
		y++;
	}
	return (map_copy);
}
