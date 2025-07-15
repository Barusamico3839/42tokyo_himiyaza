/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   48.update_player_position.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:00:00 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/30 20:00:00 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	update_player_position(t_map *map, t_player_data *pd, int nx, int ny)
{
	if (map->g_map[*(pd->py)][*(pd->px)] == pd->mark)
		map->g_map[*(pd->py)][*(pd->px)] = '0';
	else if (map->g_map[*(pd->py)][*(pd->px)] == pd->other)
		map->g_map[*(pd->py)][*(pd->px)] = pd->other;
	map->g_map[ny][nx] = pd->mark;
	*(pd->px) = nx;
	*(pd->py) = ny;
}
