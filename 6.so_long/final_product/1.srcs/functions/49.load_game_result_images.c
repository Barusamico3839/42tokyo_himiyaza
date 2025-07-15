/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   49.load_game_result_images.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 09:00:00 by himiyaza          #+#    #+#             */
/*   Updated: 2025/07/01 09:00:00 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	load_game_result_images(t_map *map)
{
	int	width;
	int	height;

	map->player1_wins_img = mlx_xpm_file_to_image(map->mlx,
			"2.textures/player1wins.xpm", &width, &height);
	map->player2_wins_img = mlx_xpm_file_to_image(map->mlx,
			"2.textures/player2wins.xpm", &width, &height);
	map->player1_loses_img = mlx_xpm_file_to_image(map->mlx,
			"2.textures/player1loses.xpm", &width, &height);
	map->player2_loses_img = mlx_xpm_file_to_image(map->mlx,
			"2.textures/player2loses.xpm", &width, &height);
}
