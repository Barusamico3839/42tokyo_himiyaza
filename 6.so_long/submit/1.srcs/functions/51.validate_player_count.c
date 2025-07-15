/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   51.validate_player_count.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:00:00 by himiyaza          #+#    #+#             */
/*   Updated: 2025/07/01 16:00:00 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	validate_player_count(t_map *map)
{
	int		y;
	int		x;
	int		player2_count;
	char	c;

	player2_count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			c = map->g_map[y][x];
			if (c == 'Q')
				player2_count++;
			x++;
		}
		y++;
	}
	if (player2_count > 1)
	{
		ft_printf("Error\n");
		ft_printf("Map must contain at most 1 'Q'\n");
		exit(1);
	}
}
