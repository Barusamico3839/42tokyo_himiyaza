/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   18.map_is_invalid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:59:15 by himiyaza          #+#    #+#             */
/*   Updated: 2024/12/19 09:59:15 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	map_is_invalid(t_map *map)
{
	if (!map)
	{
		perror("Error\nMap is NULL");
		exit(1);
	}
	if (map->width <= 0 || map->height <= 0)
	{
		perror("Error\nInvalid map dimensions");
		exit(1);
	}
	if (!map->g_map)
	{
		perror("Error\nMap data is NULL");
		exit(1);
	}
}
