/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   52.flood_fill_with_collectibles.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:00:00 by himiyaza          #+#    #+#             */
/*   Updated: 2025/07/01 16:00:00 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	count_remaining_collectibles(t_map *map)
{
	int	y;
	int	x;
	int	count;

	count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->g_map_copy[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static void	flood_fill_mark_all(int x, int y, t_map *map)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return ;
	if (map->g_map_copy[y][x] == '1' || map->g_map_copy[y][x] == 'V'
		|| map->g_map_copy[y][x] == 'E')
		return ;
	map->g_map_copy[y][x] = 'V';
	flood_fill_mark_all(x + 1, y, map);
	flood_fill_mark_all(x - 1, y, map);
	flood_fill_mark_all(x, y + 1, map);
	flood_fill_mark_all(x, y - 1, map);
}

static int	check_exit_reachable(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->g_map[y][x] == 'E')
			{
				if ((x > 0 && map->g_map_copy[y][x - 1] == 'V')
					|| (x < map->width - 1 && map->g_map_copy[y][x + 1] == 'V')
					|| (y > 0 && map->g_map_copy[y - 1][x] == 'V')
					|| (y < map->height - 1 && map->g_map_copy[y
						+ 1][x] == 'V'))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	flood_fill_with_collectibles(int x, int y, t_map *map)
{
	int	remaining_collectibles;

	flood_fill_mark_all(x, y, map);
	remaining_collectibles = count_remaining_collectibles(map);
	if (remaining_collectibles > 0)
		return (0);
	return (check_exit_reachable(map));
}
