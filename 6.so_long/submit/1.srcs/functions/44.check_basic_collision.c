/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   44.check_basic_collision.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:00:00 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/30 20:00:00 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_basic_collision(t_map *map, t_player_data *pd, int nx, int ny)
{
	if (pd->who == 'Q' && (*(pd->px) < 0 || *(pd->py) < 0
			|| map->g_map[*(pd->py)][*(pd->px)] != 'Q'))
		return (0);
	if (nx < 0 || nx >= map->width || ny < 0 || ny >= map->height)
		return (0);
	if (map->g_map[ny][nx] == '1' || (nx == pd->ox && ny == pd->oy))
		return (0);
	return (1);
}
