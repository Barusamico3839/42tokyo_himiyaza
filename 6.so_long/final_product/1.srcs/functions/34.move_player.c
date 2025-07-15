/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   34.move_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:07:15 by himiyaza          #+#    #+#             */
/*   Updated: 2024/12/19 10:07:15 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// プレイヤー移動に関する全ての関数は個別ファイルに分割されました
static void	setup_who_data(t_player_data *pd, char who)
{
	pd->who = who;
}
// プレイヤー移動のメイン関数
void	move_player(t_map *map, char who, int dx, int dy)
{
	t_player_data	pd;
	int				nx;
	int				ny;

	// プレイヤーデータの初期設定
	setup_who_data(&pd, who);
	setup_player_data(map, &pd, dx, dy);
	// 新しい位置を計算
	nx = *(pd.px) + dx;
	ny = *(pd.py) + dy;
	// 移動可能かチェック
	if (!check_movement_validity(map, &pd, nx, ny))
		return ;
	// 出口での勝利チェック
	if (check_exit_conditions(map, &pd, nx, ny))
		return ;
	// プレイヤー位置を更新
	update_player_position(map, &pd, nx, ny);
}
