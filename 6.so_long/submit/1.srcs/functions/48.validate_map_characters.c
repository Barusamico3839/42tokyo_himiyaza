/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   48.validate_map_characters.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:00:00 by himiyaza          #+#    #+#             */
/*   Updated: 2025/07/01 16:00:00 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	is_valid_character(char c)
{
	return (c == '1' || c == '0' || c == 'P' || c == 'Q' || c == 'E' || c == 'C'
		|| c == '\n' || c == '\0' || c == 'W' || c == 'X' || c == 'Y'
		|| c == 'Z');
}

void	validate_map_characters(t_map *map)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			c = map->g_map[y][x];
			if (!is_valid_character(c))
			{
				ft_printf("Error\n");
				ft_printf("Invalid character '%c' found\n", c);
				exit(1);
			}
			x++;
		}
		y++;
	}
}
