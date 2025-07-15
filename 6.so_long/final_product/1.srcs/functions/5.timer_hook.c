/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.timer_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:51:31 by himiyaza          #+#    #+#             */
/*   Updated: 2025/07/01 03:25:07 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/*
** mlx_loop_hook() に登録して
** 毎フレーム呼び出されるたびに frame_count++ するだけ
*/
int	timer_hook(void *param)
{
	t_map		*map;
	t_timeval	*tm;
	static long	last_frame = 0;
	t_timeval	now;

	map = (t_map *)param;
	tm = map->tm;
	if (map->timer_enabled == 0)
		return (0); // タイマー停止
	tm->frame_count++;
	move_all_enemies(map);
	check_player_enemy_collision(map);
	ft_gettimeofday(tm, &now);
	if (tm->frame_count - last_frame > CPU_SPEED * difficulty_var(1))
	{
		if (map->view_offset_y > 0)
			map->view_offset_y--;
		check_player_out_of_screen(map);
		last_frame = tm->frame_count;
	}
	draw_map(map);
	return (0);
}
