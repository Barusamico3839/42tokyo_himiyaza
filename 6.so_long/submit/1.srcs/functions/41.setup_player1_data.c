/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   41.setup_player1_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:00:00 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/30 20:00:00 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	setup_player1_data(t_map *map, t_player_data *pd, int dx, int dy)
{
	if (!map->player1_wins && !map->player2_wins && !map->player1_loses
		&& !map->player2_loses)
	{
		map->player1_moves++;
		map->show_moves = 1;
		ft_printf("player1 moves: %d\n", map->player1_moves);
	}
	pd->px = &map->player1_x;
	pd->py = &map->player1_y;
	pd->ox = map->player2_x;
	pd->oy = map->player2_y;
	pd->mark = 'P';
	pd->other = 'Q';
	if (dx > 0)
		map->player1_dir = 1;
	else if (dx < 0)
		map->player1_dir = 0;
	else if (dy < 0)
		map->player1_dir = 2;
	else if (dy > 0)
		map->player1_dir = 3;
}
