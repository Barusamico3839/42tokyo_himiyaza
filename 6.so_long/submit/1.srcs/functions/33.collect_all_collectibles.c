/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   33.collect_all_collectibles.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:06:45 by himiyaza          #+#    #+#             */
/*   Updated: 2024/12/19 10:06:45 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	collect_all_collectibles(t_map *map)
{
	int	y;
	int	x;

	if (MODE_COLLECTABLES == 0)
		return (1);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->g_map[y][x] == 'C')
			{
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
