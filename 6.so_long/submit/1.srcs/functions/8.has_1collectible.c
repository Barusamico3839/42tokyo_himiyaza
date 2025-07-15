/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8.has_1collectible.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:54:05 by himiyaza          #+#    #+#             */
/*   Updated: 2024/12/19 09:54:05 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	has_1collectible(t_map *map)
{
	int	collectible_count;
	int	y;
	int	x;

	collectible_count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->g_map[y][x] == 'C')
				collectible_count++;
			x++;
		}
		y++;
	}
	if (!collectible_count)
	{
		ft_printf("Error\nMap must have more than one collectible.\n");
		exit(1);
	}
}
