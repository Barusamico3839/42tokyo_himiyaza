/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   47.check_exit_conditions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:00:00 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/30 20:00:00 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_exit_conditions(t_map *map, t_player_data *pd, int nx, int ny)
{
	if (pd->who == 'P' && map->g_map[ny][nx] == 'E')
	{
		if (collect_all_collectibles(map) == 1)
		{
			map->player1_wins = 1;
		}
		return (1);
	}
	if (pd->who == 'Q' && map->g_map[ny][nx] == 'E')
	{
		map->player2_wins = 1;
		return (1);
	}
	return (0);
}
