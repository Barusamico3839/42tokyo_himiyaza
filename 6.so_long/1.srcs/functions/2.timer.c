/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.timer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:18:54 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/27 10:34:35 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_timeval	*init_timer(int fps)
{
	t_timeval	*tm;

	tm = malloc(sizeof(t_timeval));
	if (!tm)
	{
		write(2, "Error: init_timer failed\n", 26);
		exit(1);
	}
	tm->frame_count = 0;
	tm->frame_dt_us = 1000000 / fps;
	return (tm);
}

/*
** gettimeofday() 相当：
**   frame_count * frame_dt_us から秒とマイクロ秒を算出
*/
int	ft_gettimeofday(t_timeval *tm, t_timeval *tv)
{
	long	total_us;

	if (!tm || !tv)
		return (-1);
	// printf("frame_count: %lld, frame_dt_us: %d\n", tm->frame_count,
		// tm->frame_dt_us;
		total_us = tm->frame_count * tm->frame_dt_us;
		tv->tv_sec = total_us / 10000000;
		tv->tv_usec = total_us % 10000000;
		return (0);
}

/*
** mlx_loop_hook() に登録して
** 毎フレーム呼び出されるたびに frame_count++ するだけ
*/
int timer_hook(void *param)
{
    t_map      *map = (t_map *)param;
    t_timeval  *tm = map->tm;
    static long last_frame = 0;
    t_timeval  now;

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
