/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   34.move_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:07:15 by himiyaza          #+#    #+#             */
/*   Updated: 2024/12/19 10:07:15 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	setup_who_data(t_player_data *pd, char who)
{
	pd->who = who;
}

void	move_player(t_map *map, char who, int dx, int dy)
{
	t_player_data	pd;
	int				nx;
	int				ny;

	setup_who_data(&pd, who);
	setup_player_data(map, &pd, dx, dy);
	nx = *(pd.px) + dx;
	ny = *(pd.py) + dy;
	if (!check_movement_validity(map, &pd, nx, ny))
		return ;
	if (check_exit_conditions(map, &pd, nx, ny))
		return ;
	update_player_position(map, &pd, nx, ny);
}
