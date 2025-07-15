/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   50.draw_game_result_screen.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 09:00:00 by himiyaza          #+#    #+#             */
/*   Updated: 2025/07/01 09:00:00 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	draw_game_result_screen(t_map *map)
{
	void	*result_img;

	result_img = NULL;
	if (map->player1_wins && map->player1_wins_img)
		result_img = map->player1_wins_img;
	else if (map->player2_wins && map->player2_wins_img)
		result_img = map->player2_wins_img;
	else if (map->player1_loses && map->player1_loses_img)
		result_img = map->player1_loses_img;
	else if (map->player2_loses && map->player2_loses_img)
		result_img = map->player2_loses_img;
	if (result_img)
		mlx_put_image_to_window(map->mlx, map->win, result_img, 0, 0);
}
