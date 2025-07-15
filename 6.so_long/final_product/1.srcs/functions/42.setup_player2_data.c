/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42.setup_player2_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:00:00 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/30 20:00:00 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	setup_player2_data(t_map *map, t_player_data *pd, int dx, int dy)
{
	pd->px = &map->player2_x;
	pd->py = &map->player2_y;
	pd->ox = map->player1_x;
	pd->oy = map->player1_y;
	pd->mark = 'Q';
	pd->other = 'P';
	if (dx > 0)
		map->player2_dir = 1;
	else if (dx < 0)
		map->player2_dir = 0;
	else if (dy < 0)
		map->player2_dir = 2;
	else if (dy > 0)
		map->player2_dir = 3;
}
