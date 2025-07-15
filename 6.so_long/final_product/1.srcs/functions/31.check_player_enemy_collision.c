/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   31.check_player_enemy_collision.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:05:45 by himiyaza          #+#    #+#             */
/*   Updated: 2024/12/19 10:05:45 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_player_enemy_collision(t_map *map)
{
	if (is_enemy_tile(map->g_map[map->player1_y][map->player1_x]))
	{
		map->player1_loses = 1;
		map->timer_enabled = 0;
	}
	else if (map->player2_x >= 0 && map->player2_y >= 0
		&& is_enemy_tile(map->g_map[map->player2_y][map->player2_x]))
	{
		map->player2_loses = 1;
		map->timer_enabled = 0;
	}
}
