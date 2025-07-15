/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   40.setup_map_structure.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:51:30 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/30 16:51:30 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	setup_map_structure(t_map *map, int width, int height)
{
	map->width = width;
	map->height = height;
	map->g_map = malloc(sizeof(char *) * height);
	if (!map->g_map)
	{
		ft_printf("Error\nfailed malloc at find_map_size");
		if (map->stdin_or_header == 1)
			free(map->map_name);
		exit(1);
	}
}
