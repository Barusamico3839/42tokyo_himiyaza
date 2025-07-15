/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:52:04 by himiyaza          #+#    #+#             */
/*   Updated: 2025/07/01 10:42:34 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		ft_printf("Error\nFailed to allocate memory for map\n");
		exit(1);
	}
	stdin_error_check(argc, argv, map);
	maperror(map);
	map->mlx = mlx_init();
	nakami(*map);
	return (1);
}
