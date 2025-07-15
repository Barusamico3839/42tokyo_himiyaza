/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   36.nakami.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:08:15 by himiyaza          #+#    #+#             */
/*   Updated: 2024/12/19 10:08:15 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	init_game_state(t_map *map)
{
	map->player1_loses = 0;
	map->player2_loses = 0;
	map->player1_wins = 0;
	map->player2_wins = 0;
	map->player1_moves = 0;
	map->player1_moves = 0;
	map->last_player1_moves = 0;
	map->show_moves = 0;
	map->tm = init_timer(60);
	map->timer_enabled = 1;
	find_players(map);
	map->player1_dir = 3;
	map->player2_dir = 3;
	init_enemies(map);
	map->view_offset_y = map->height - VIEW_H;
	if (map->view_offset_y < 0)
		map->view_offset_y = 0;
}

static void	load_some_images(t_map *map)
{
	int	img_w;
	int	img_h;

	map->wall_img = mlx_xpm_file_to_image(map->mlx, "2.textures/wall.xpm",
			&img_w, &img_h);
	map->empty_img = mlx_xpm_file_to_image(map->mlx, "2.textures/empty.xpm",
			&img_w, &img_h);
	map->collect_img = mlx_xpm_file_to_image(map->mlx, "2.textures/collect.xpm",
			&img_w, &img_h);
	map->exit_img = mlx_xpm_file_to_image(map->mlx, "2.textures/exit.xpm",
			&img_w, &img_h);
	map->enemy_img = mlx_xpm_file_to_image(map->mlx, "2.textures/enemy.xpm",
			&img_w, &img_h);
}

static void	load_all_images(t_map *map)
{
	int	img_w;
	int	img_h;

	map->player1_img_left = mlx_xpm_file_to_image(map->mlx,
			"2.textures/player1_left.xpm", &img_w, &img_h);
	map->player1_img_right = mlx_xpm_file_to_image(map->mlx,
			"2.textures/player1_right.xpm", &img_w, &img_h);
	map->player1_img_up = mlx_xpm_file_to_image(map->mlx,
			"2.textures/player1_up.xpm", &img_w, &img_h);
	map->player1_img_down = mlx_xpm_file_to_image(map->mlx,
			"2.textures/player1_down.xpm", &img_w, &img_h);
	map->player2_img_left = mlx_xpm_file_to_image(map->mlx,
			"2.textures/player2_left.xpm", &img_w, &img_h);
	map->player2_img_right = mlx_xpm_file_to_image(map->mlx,
			"2.textures/player2_right.xpm", &img_w, &img_h);
	map->player2_img_up = mlx_xpm_file_to_image(map->mlx,
			"2.textures/player2_up.xpm", &img_w, &img_h);
	map->player2_img_down = mlx_xpm_file_to_image(map->mlx,
			"2.textures/player2_down.xpm", &img_w, &img_h);
	load_some_images(map);
	load_game_result_images(map);
}

static void	setup_window_and_start_game(t_map *map)
{
	map->win = mlx_new_window(map->mlx, VIEW_W * TILE, VIEW_H * TILE, "ATAOKA");
	mlx_hook(map->win, 17, 0, close_window, NULL);
	mlx_hook(map->win, 2, 1L << 0, wasd_jyuji_key, map);
	mlx_loop_hook(map->mlx, timer_hook, map);
	draw_map(map);
	mlx_loop(map->mlx);
}

int	nakami(t_map map)
{
	init_game_state(&map);
	load_all_images(&map);
	setup_window_and_start_game(&map);
	return (1);
}
