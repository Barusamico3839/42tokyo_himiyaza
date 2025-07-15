/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   25.draw_win_screen.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:02:45 by himiyaza          #+#    #+#             */
/*   Updated: 2024/12/19 10:02:45 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	draw_win_screen(void *mlx, void *win, const char *msg, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < VIEW_H * TILE)
	{
		x = 0;
		while (x < VIEW_W * TILE)
		{
			mlx_pixel_put(mlx, win, x, y, color);
			x++;
		}
		y++;
	}
	mlx_string_put(mlx, win, VIEW_W * TILE / 2 - 60, VIEW_H * TILE / 2,
		0xFFFFFF, (char *)msg);
}
