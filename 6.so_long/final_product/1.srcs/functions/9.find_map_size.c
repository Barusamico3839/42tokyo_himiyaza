/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9.find_map_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:54:35 by himiyaza          #+#    #+#             */
/*   Updated: 2024/12/19 09:54:35 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	find_map_size(t_map *map)
{
	int	fd;
	int	width;
	int	height;

	fd = open_map_file(map);
	width = get_map_width(fd, map);
	close(fd);
	fd = open_map_file(map);
	height = validate_map_rectangle(fd, width, map);
	setup_map_structure(map, width, height);
}
