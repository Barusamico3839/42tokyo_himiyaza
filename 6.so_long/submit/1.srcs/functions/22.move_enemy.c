/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   22.move_enemy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:01:15 by himiyaza          #+#    #+#             */
/*   Updated: 2024/12/19 10:01:15 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	calculate_next_position(t_map *map, t_enemy *enemy, int *nx,
		int *ny)
{
	*nx = enemy->x + enemy->dir;
	*ny = enemy->y;
	if (*nx < 0 || *nx >= map->width || map->g_map[*ny][*nx] == '1')
	{
		enemy->dir *= -1;
		*nx = enemy->x + enemy->dir;
		if (*nx < 0 || *nx >= map->width || map->g_map[*ny][*nx] == '1')
			return (0);
	}
	if (map->g_map[*ny][*nx] == 'P')
	{
		map->player1_loses = 1;
		map->timer_enabled = 0;
		return (0);
	}
	if (map->g_map[*ny][*nx] == 'Q')
	{
		map->player2_loses = 1;
		map->timer_enabled = 0;
		return (0);
	}
	return (1);
}

static void	update_enemy_position(t_map *map, t_enemy *enemy, int nx, int ny)
{
	if (map->g_map[enemy->y][enemy->x] == enemy->symbol)
		map->g_map[enemy->y][enemy->x] = '0';
	map->g_map[ny][nx] = enemy->symbol;
	enemy->x = nx;
	enemy->y = ny;
}

void	move_enemy(t_map *map, t_enemy *enemy)
{
	int	nx;
	int	ny;

	enemy->frame++;
	if (enemy->frame < enemy->speed)
		return ;
	enemy->frame = 0;
	if (!calculate_next_position(map, enemy, &nx, &ny))
		return ;
	update_enemy_position(map, enemy, nx, ny);
}
