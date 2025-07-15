/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   39.validate_map_rectangle.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:51:00 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/30 16:51:00 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	validate_line_width(char *line, int width, int fd, t_map *map)
{
	int	len;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	if (len != width && len != 0)
	{
		ft_printf("Error\nMap is not rectangular\n");
		free(line);
		close(fd);
		if (map->stdin_or_header == 1)
		{
			free(map->map_name);
			exit(1);
		}
	}
}

static int	count_map_lines(int fd, int width, t_map *map)
{
	char	*line;
	int		height;

	height = 0;
	reset_get_next_line();
	line = get_next_line(fd);
	while (line != NULL)
	{
		validate_line_width(line, width, fd, map);
		free(line);
		line = get_next_line(fd);
		height++;
	}
	return (height);
}

int	validate_map_rectangle(int fd, int width, t_map *map)
{
	int	height;

	height = count_map_lines(fd, width, map);
	close(fd);
	return (height);
}
