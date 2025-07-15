/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   45.check_enemy_collision.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:00:00 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/30 20:00:00 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_enemy_collision(t_map *map, t_player_data *pd, int nx, int ny)
{
	if (is_enemy_tile(map->g_map[ny][nx]))
	{
		if (pd->who == 'P')
		{
			map->player1_loses = 1;
			map->timer_enabled = 0;
		}
		else
		{
			map->player2_loses = 1;
			map->timer_enabled = 0;
		}
		return (0);
	}
	return (1);
}
