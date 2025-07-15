/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   23.move_all_enemies.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:01:45 by himiyaza          #+#    #+#             */
/*   Updated: 2024/12/19 10:01:45 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	move_all_enemies(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->enemy_count)
	{
		move_enemy(map, &map->enemies[i]);
		i++;
	}
}
