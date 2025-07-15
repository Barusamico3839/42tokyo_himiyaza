/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:52:04 by himiyaza          #+#    #+#             */
/*   Updated: 2025/07/01 03:24:46 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		perror("Error\nFailed to allocate memory for map");
		exit(1);
	}
	stdin_error_check(argc, argv, map);
	maperror(map);
	map->mlx = mlx_init(); // mlxの機能を使う前に一度呼び出す必要がある
	nakami(*map);          // nakami関数を呼び出す
	return (1);
}
