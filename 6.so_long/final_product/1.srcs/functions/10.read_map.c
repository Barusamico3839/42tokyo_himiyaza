/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10.read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:55:10 by himiyaza          #+#    #+#             */
/*   Updated: 2025/07/01 03:25:29 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	open_and_free(t_map *map)
{
	int	fd;

	fd = open(map->map_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nFailed to open %s\n", map->map_name);
		exit(1);
	}
	if (map->map_name != NULL && map->stdin_or_header == 1)
		free(map->map_name);
	return (fd);
}

void	read_map(t_map *map)
{
	int		fd;
	int		i;
	char	*line;

	fd = open_and_free(map);
	i = 0;
	while (i < map->height)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			ft_printf("Error\nUnexpected end of file while reading map\n");
			close(fd);
			exit(1);
		}
		if (line[0] == '\n')
		{
			free(line);
			continue ;
		}
		map->g_map[i] = line;
		i++;
	}
	close(fd);
}
