/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13.flood_fill_recursive.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:56:45 by himiyaza          #+#    #+#             */
/*   Updated: 2024/12/19 09:56:45 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	flood_fill_recursive(int x, int y, t_map *map)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return (0);
	if (map->g_map_copy[y][x] == '1' || map->g_map_copy[y][x] == 'V')
		return (0);
	if (map->g_map_copy[y][x] == 'E')
		return (1);
	map->g_map_copy[y][x] = 'V';
	if (flood_fill_recursive(x + 1, y, map) || flood_fill_recursive(x - 1, y,
			map) || flood_fill_recursive(x, y + 1, map)
		|| flood_fill_recursive(x, y - 1, map))
		return (1);
	return (0);
}
