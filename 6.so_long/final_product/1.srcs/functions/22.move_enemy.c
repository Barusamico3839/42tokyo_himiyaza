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

// 敵の次の位置を計算し、移動可能かチェックする関数
static int	calculate_next_position(t_map *map, t_enemy *enemy, int *nx,
		int *ny)
{
	*nx = enemy->x + enemy->dir;
	*ny = enemy->y;
	// 壁や境界に当たった場合、方向を変更
	if (*nx < 0 || *nx >= map->width || map->g_map[*ny][*nx] == '1')
	{
		enemy->dir *= -1;
		*nx = enemy->x + enemy->dir;
		if (*nx < 0 || *nx >= map->width || map->g_map[*ny][*nx] == '1')
			return (0); // 移動不可
	}
	// プレイヤーとの衝突チェック
	if (map->g_map[*ny][*nx] == 'P')
	{
		map->player1_loses = 1;
		map->timer_enabled = 0;
		return (0); // 移動不可（ゲーム終了）
	}
	if (map->g_map[*ny][*nx] == 'Q')
	{
		map->player2_loses = 1;
		map->timer_enabled = 0;
		return (0); // 移動不可（ゲーム終了）
	}
	return (1); // 移動可能
}

// 敵をマップ上で実際に移動させる関数
static void	update_enemy_position(t_map *map, t_enemy *enemy, int nx, int ny)
{
	// 元の位置を消す（プレイヤーがいなければ）
	if (map->g_map[enemy->y][enemy->x] == enemy->symbol)
		map->g_map[enemy->y][enemy->x] = '0';
	// 新しい位置に敵を配置
	map->g_map[ny][nx] = enemy->symbol;
	enemy->x = nx;
	enemy->y = ny;
}

// 敵の移動を管理するメイン関数
void	move_enemy(t_map *map, t_enemy *enemy)
{
	int	nx;
	int	ny;

	enemy->frame++;
	if (enemy->frame < enemy->speed)
		return ;
	enemy->frame = 0;
	// 次の位置を計算し、移動可能かチェック
	if (!calculate_next_position(map, enemy, &nx, &ny))
		return ;
	// 敵の位置を更新
	update_enemy_position(map, enemy, nx, ny);
}
