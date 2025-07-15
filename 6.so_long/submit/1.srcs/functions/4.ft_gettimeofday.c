/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.ft_gettimeofday.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:00:00 by himiyaza          #+#    #+#             */
/*   Updated: 2025/07/01 04:00:22 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_gettimeofday(t_timeval *tm, t_timeval *tv)
{
	long	total_us;

	if (!tm || !tv)
		return (-1);
	total_us = tm->frame_count * tm->frame_dt_us;
	tv->tv_sec = total_us / 10000000;
	tv->tv_usec = total_us % 10000000;
	return (0);
}
