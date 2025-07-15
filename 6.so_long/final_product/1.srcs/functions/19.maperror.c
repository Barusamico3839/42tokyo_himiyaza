/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   19.maperror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:59:45 by himiyaza          #+#    #+#             */
/*   Updated: 2024/12/19 09:59:45 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	maperror(t_map *map)
{
	find_map_size(map);
	read_map(map);
	// is_valid_fd();
	is_valid_difficulty();
	map_is_invalid(map);
	has_exit_startingpos(map);
	has_1collectible(map);
	is_sorrounded_by_walls(map);
	has_valid_path(map);
}
