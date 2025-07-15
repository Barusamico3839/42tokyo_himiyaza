/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   29.find_players.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:04:45 by himiyaza          #+#    #+#             */
/*   Updated: 2024/12/19 10:04:45 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	if_p_found(t_map *map, int *found_p, int x, int y)
{
	if (!*found_p && map->g_map[y][x] == 'P')
	{
		map->player1_x = x;
		map->player1_y = y;
		*found_p = 1;
	}
}

static void	if_q_found(t_map *map, int *found_q, int x, int y)
{
	if (!*found_q && map->g_map[y][x] == 'Q')
	{
		map->player2_x = x;
		map->player2_y = y;
		*found_q = 1;
	}
}

// マップ上でプレイヤーを検索する関数
static void	search_players_in_map(t_map *map, int *found_p, int *found_q)
{
	int	y;
	int	x;

	*found_p = 0;
	*found_q = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if_p_found(map, found_p, x, y);
			if_q_found(map, found_q, x, y);
			if (*found_p && *found_q)
				return ;
			x++;
		}
		y++;
	}
}

// プレイヤー初期位置を探す
void	find_players(t_map *map)
{
	int	found_p;
	int	found_q;

	search_players_in_map(map, &found_p, &found_q);
	if (!found_p)
	{
		perror("Error\nPlayer P not found in map");
		exit(1);
	}
	// Qがいなければ無効値をセット
	if (!found_q)
	{
		map->player2_x = -1;
		map->player2_y = -1;
	}
}
