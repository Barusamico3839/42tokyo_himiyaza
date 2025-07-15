/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.init_timer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:00:00 by himiyaza          #+#    #+#             */
/*   Updated: 2025/07/01 03:24:54 by himiyaza         ###   ########.fr       */
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
