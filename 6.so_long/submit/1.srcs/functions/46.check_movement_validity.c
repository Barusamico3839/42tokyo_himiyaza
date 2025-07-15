/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   46.check_movement_validity.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:00:00 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/30 20:00:00 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_movement_validity(t_map *map, t_player_data *pd, int nx, int ny)
{
	if (!check_basic_collision(map, pd, nx, ny))
		return (0);
	if (!check_enemy_collision(map, pd, nx, ny))
		return (0);
	return (1);
}
