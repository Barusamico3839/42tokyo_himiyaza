/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   43.setup_player_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:00:00 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/30 20:00:00 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	setup_player_data(t_map *map, t_player_data *pd, int dx, int dy)
{
	pd->dx = dx;
	pd->dy = dy;
	if (pd->who == 'P')
		setup_player1_data(map, pd, dx, dy);
	else
		setup_player2_data(map, pd, dx, dy);
}
