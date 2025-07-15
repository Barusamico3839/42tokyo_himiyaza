/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   37.open_map_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:50:00 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/30 16:50:00 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	open_map_file(t_map *map)
{
	int	fd;

	fd = open(map->map_name, O_RDONLY);
	if (fd < 0)
	{
		free(map->map_name);
		ft_printf("Error\nFailed to open map file");
		if (map->stdin_or_header == 1)
			free(map->map_name);
		exit(1);
	}
	return (fd);
}
