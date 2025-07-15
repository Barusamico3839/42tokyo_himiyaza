/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   24.draw_tile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:02:15 by himiyaza          #+#    #+#             */
/*   Updated: 2024/12/19 10:02:15 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	draw_basic_tiles(int x, int y, char c, t_map *map)
{
	if (c == '1' && map->wall_img)
		mlx_put_image_to_window(map->mlx, map->win, map->wall_img, x * TILE, y
			* TILE);
	else if (c == '0' && map->empty_img)
		mlx_put_image_to_window(map->mlx, map->win, map->empty_img, x * TILE, y
			* TILE);
	else if (c == 'C' && map->collect_img)
		mlx_put_image_to_window(map->mlx, map->win, map->collect_img, x * TILE,
			y * TILE);
	else if (c == 'E' && map->exit_img)
		mlx_put_image_to_window(map->mlx, map->win, map->exit_img, x * TILE, y
			* TILE);
	else if ((c == 'W' || c == 'X' || c == 'Y' || c == 'Z') && map->enemy_img)
		mlx_put_image_to_window(map->mlx, map->win, map->enemy_img, x * TILE, y
			* TILE);
}

static void	draw_player1(int x, int y, t_map *map)
{
	if (map->player1_dir == 0 && map->player1_img_left)
		mlx_put_image_to_window(map->mlx, map->win, map->player1_img_left, x
			* TILE, y * TILE);
	else if (map->player1_dir == 1 && map->player1_img_right)
		mlx_put_image_to_window(map->mlx, map->win, map->player1_img_right, x
			* TILE, y * TILE);
	else if (map->player1_dir == 2 && map->player1_img_up)
		mlx_put_image_to_window(map->mlx, map->win, map->player1_img_up, x
			* TILE, y * TILE);
	else if (map->player1_dir == 3 && map->player1_img_down)
		mlx_put_image_to_window(map->mlx, map->win, map->player1_img_down, x
			* TILE, y * TILE);
}

static void	draw_player2(int x, int y, t_map *map)
{
	if (map->player2_dir == 0 && map->player2_img_left)
		mlx_put_image_to_window(map->mlx, map->win, map->player2_img_left, x
			* TILE, y * TILE);
	else if (map->player2_dir == 1 && map->player2_img_right)
		mlx_put_image_to_window(map->mlx, map->win, map->player2_img_right, x
			* TILE, y * TILE);
	else if (map->player2_dir == 2 && map->player2_img_up)
		mlx_put_image_to_window(map->mlx, map->win, map->player2_img_up, x
			* TILE, y * TILE);
	else if (map->player2_dir == 3 && map->player2_img_down)
		mlx_put_image_to_window(map->mlx, map->win, map->player2_img_down, x
			* TILE, y * TILE);
}

static void	draw_fallback_tile(int x, int y, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE)
	{
		j = 0;
		while (j < TILE)
		{
			mlx_pixel_put(map->mlx, map->win, x * TILE + i, y * TILE + j,
				0xFF00FF);
			j++;
		}
		i++;
	}
}

void	draw_tile(int x, int y, char c, t_map *map)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'W' || c == 'X'
		|| c == 'Y' || c == 'Z')
		draw_basic_tiles(x, y, c, map);
	else if (c == 'P')
		draw_player1(x, y, map);
	else if (c == 'Q')
		draw_player2(x, y, map);
	else
		draw_fallback_tile(x, y, map);
}
