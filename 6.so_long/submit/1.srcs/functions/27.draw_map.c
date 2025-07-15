/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   27.draw_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:03:45 by himiyaza          #+#    #+#             */
/*   Updated: 2024/12/19 10:03:45 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	draw_normal_game(t_map *map)
{
	int	x;
	int	y;
	int	map_y;

	if (!map || !map->g_map)
		return ;
	y = 0;
	while (y < VIEW_H && (map->view_offset_y + y) < map->height)
	{
		x = 1;
		map_y = map->view_offset_y + y;
		while (x < VIEW_W + 1 && x < map->width)
		{
			if (map->g_map[map_y])
				draw_tile(x - 1, y, map->g_map[map_y][x], map);
			x++;
		}
		y++;
	}
	mlx_string_put(map->mlx, map->win, 10, 20, 0x000000, "moves:");
	ft_putnbr_mlx(map->player1_moves, map, 50, 20);
}

static void	draw_result_screen(t_map *map)
{
	if (map->player1_wins || map->player2_wins || map->player1_loses
		|| map->player2_loses)
	{
		draw_game_result_screen(map);
	}
}

void	draw_map(t_map *map)
{
	if (map->player1_wins || map->player2_wins || map->player1_loses
		|| map->player2_loses)
	{
		draw_result_screen(map);
		return ;
	}
	draw_normal_game(map);
}
