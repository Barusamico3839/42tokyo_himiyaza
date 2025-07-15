/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15.has_exit_startingpos.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:57:45 by himiyaza          #+#    #+#             */
/*   Updated: 2024/12/19 09:57:45 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_exit_count(int exit_count, int starting_pos_countP)
{
	if (exit_count != 1)
	{
		ft_printf("Error\nMap must have exactly one E\n");
		exit(1);
	}
	if (starting_pos_countP != 1)
	{
		ft_printf("Error\nMap must have exactly one P\n");
		exit(1);
	}
}

void	has_exit_startingpos(t_map *map)
{
	int	exit_count;
	int	starting_pos_countP;
	int	y;
	int	x;

	exit_count = 0;
	starting_pos_countP = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->g_map[y][x] == 'E')
				exit_count++;
			else if (map->g_map[y][x] == 'P')
				starting_pos_countP++;
			x++;
		}
		y++;
	}
	check_exit_count(exit_count, starting_pos_countP);
}
