/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21.init_enemies.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:00:45 by himiyaza          #+#    #+#             */
/*   Updated: 2024/12/19 10:00:45 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	is_enemy_char(char c)
{
	return (c == 'W' || c == 'X' || c == 'Y' || c == 'Z');
}

static int	set_enemy_speed(char c)
{
	if (c == 'W')
		return (CPU_SPEED * (7 + difficulty_var(2)));
	else if (c == 'X')
		return (CPU_SPEED * (4 + difficulty_var(2)));
	else if (c == 'Y')
		return (CPU_SPEED * (3 + difficulty_var(2) / 2));
	else if (c == 'Z')
		return (CPU_SPEED * (1 + difficulty_var(2) / 3));
	else
		return (0);
}

static void	set_single_enemy(t_map *map, int y, int n, char c)
{
	map->enemies[n].y = y;
	map->enemies[n].dir = -1;
	map->enemies[n].speed = set_enemy_speed(c);
	map->enemies[n].frame = 0;
	map->enemies[n].symbol = c;
}

void	init_enemies(t_map *map)
{
	int		y;
	int		x;
	int		n;
	char	c;

	n = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			c = map->g_map[y][x];
			if (is_enemy_char(c) && n < MAX_ENEMIES)
			{
				map->enemies[n].x = x;
				set_single_enemy(map, y, n, c);
				n++;
			}
			x++;
		}
		y++;
	}
	map->enemy_count = n;
}
