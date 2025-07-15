/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   38.get_map_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:50:30 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/30 16:50:30 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	get_map_width(int fd, t_map *map)
{
	char	*line;
	int		len;
	int		width;

	line = get_next_line(fd);
	if (line == NULL)
	{
		ft_printf("Error\nFailed malloc at gnl");
		close(fd);
		if (map->stdin_or_header == 1)
			free(map->map_name);
		else
			ft_printf("Error\nMap file is empty\n");
		if (map->stdin_or_header == 1)
			free(map->map_name);
		exit(1);
	}
	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	width = len;
	free(line);
	return (width);
}
