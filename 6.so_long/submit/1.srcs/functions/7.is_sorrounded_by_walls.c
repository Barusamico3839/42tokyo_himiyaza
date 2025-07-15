/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7.is_sorrounded_by_walls.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 04:22:07 by himiyaza          #+#    #+#             */
/*   Updated: 2025/07/01 04:22:09 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	is_sorrounded_by_walls(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (x < map->width)
	{
		if (map->g_map[0][x] != '1' || map->g_map[map->height - 1][x] != '1')
		{
			ft_printf("Error\nMap must be sorrounded by walls.\n");
			exit(1);
		}
		x++;
	}
	while (y + 1 < map->height - 1)
	{
		if (map->g_map[y][0] != '1' || map->g_map[y][map->width - 1] != '1')
		{
			ft_printf("Error\nMap must be sorrounded by walls.\n");
			exit(1);
		}
		y++;
	}
}
