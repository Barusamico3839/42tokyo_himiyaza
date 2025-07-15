/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   35.wasd_jyuji_key.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:07:45 by himiyaza          #+#    #+#             */
/*   Updated: 2024/12/19 10:07:45 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// キー入力
int	wasd_jyuji_key(int keycode, t_map *map)
{
	// プレイヤー1: wasd
	if (keycode == 'w')
		move_player(map, 'P', 0, -1);
	else if (keycode == 's')
		move_player(map, 'P', 0, 1);
	else if (keycode == 'a')
		move_player(map, 'P', -1, 0);
	else if (keycode == 'd')
		move_player(map, 'P', 1, 0);
	// プレイヤー2: jyuji
	else if (keycode == 65362 || keycode == 'i')
		move_player(map, 'Q', 0, -1);
	else if (keycode == 65364 || keycode == 'k')
		move_player(map, 'Q', 0, 1);
	else if (keycode == 65361 || keycode == 'j')
		move_player(map, 'Q', -1, 0);
	else if (keycode == 65363 || keycode == 'l')
		move_player(map, 'Q', 1, 0);
	else if (keycode == 65307)
		exit(0);
	draw_map(map);
	return (0);
}
