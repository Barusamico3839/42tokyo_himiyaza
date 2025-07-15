/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   14.has_valid_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:57:15 by himiyaza          #+#    #+#             */
/*   Updated: 2024/12/19 09:57:15 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	find_player_P(t_map *map, int *player_x, int *player_y)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->g_map[y][x] == 'P')
			{
				*player_x = x;
				*player_y = y;
				break ;
			}
			x++;
		}
		if (*player_x >= 0)
			break ;
	}
	if (*player_x < 0 || *player_y < 0)
	{
		ft_printf("Error\nPlayer P not found in map\n");
		exit(1);
	}
}

void	has_valid_path(t_map *map)
{
	int	player_x;
	int	player_y;
	int	path_exists;

	player_x = -1;
	player_y = -1;
	find_player_P(map, &player_x, &player_y);
	// マップをコピー
	map->g_map_copy = copy_map(map);
	if (!map->g_map_copy)
	{
		ft_printf("Error\nFailed to copy map for path validation\n");
		exit(1);
	}
	// フラッドフィルで出口まで到達可能かチェック
	path_exists = flood_fill_recursive(player_x, player_y, map);
	free_map_copy(map->g_map_copy, map->height);
	if (!path_exists)
	{
		ft_printf("Error\nMap must have a valid path to exit.\n");
		exit(1);
	}
}
