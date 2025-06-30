/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 04:08:30 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/29 23:02:35 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	stdin_error_check(int argc, char **argv, t_map *map)
{
	if (argc != 2)
		ft_printf("Usage: ./so_long <map_file.ber>\n");
	is_valid_fd(argv[1], map);
}

int	main(int argc, char **argv)
{
	t_map *map;

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