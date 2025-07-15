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
		ft_printf("Error\nMap is NULL\n");
		exit(1);
	}
	if (map->width <= 0 || map->height <= 0)
	{
		ft_printf("Error\nInvalid map dimensions\n");
		exit(1);
	}
	if (!map->g_map)
	{
		ft_printf("Error\nMap data is NULL\n");
		exit(1);
	}
}
