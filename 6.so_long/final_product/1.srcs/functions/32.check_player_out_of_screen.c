/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   32.check_player_out_of_screen.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:06:15 by himiyaza          #+#    #+#             */
/*   Updated: 2024/12/19 10:06:15 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_player_out_of_screen(t_map *map)
{
	int	p1_screen_y;
	int	p2_screen_y;

	p1_screen_y = map->player1_y - map->view_offset_y;
	p2_screen_y = map->player2_y - map->view_offset_y;
	if (p1_screen_y >= VIEW_H)
	{
		map->player1_loses = 1;
		map->timer_enabled = 0;
	}
	else if (map->player2_x >= 0 && map->player2_y >= 0
		&& p2_screen_y >= VIEW_H)
	{
		map->player2_loses = 1;
		map->timer_enabled = 0;
	}
}
