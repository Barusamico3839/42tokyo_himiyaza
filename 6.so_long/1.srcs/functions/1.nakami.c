/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.nakami.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himiyaza <himiyaza@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:05:09 by himiyaza          #+#    #+#             */
/*   Updated: 2025/06/30 01:53:18 by himiyaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	is_sorrounded_by_walls(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (x < map->width)
	{
		if (map->g_map[0][x] != '1' || map->g_map[map->height - 1][x] != '1')
		{
			ft_printf("Error\nMap must be sorrounded by walls.\n");
			exit(1);
		}
		x++;
	}
	while (y + 1 < map->height - 1)
	{
		if (map->g_map[y][0] != '1' || map->g_map[y][map->width - 1] != '1')
		{
			ft_printf("Error\nMap must be sorrounded by walls.\n");
			exit(1);
		}
		y++;
	}
}

void	has_1collectible(t_map *map)
{
	int	collectible_count;
	int	y;
	int	x;

	collectible_count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->g_map[y][x] == 'C')
				collectible_count++;
			x++;
		}
		y++;
	}
	if (!collectible_count)
	{
		perror("Error\nMap must have more than one collectible.");
		exit(1);
	}
}

void	find_map_size(t_map *map)
{
	int		fd;
	int		width;
	int		height;
	int		len;
	char	*line;

	fd = open(map->map_name, O_RDONLY);
	if (fd < 0)
		exit(1);
	height = 0;
	width = 0;
	line = get_next_line(fd);
	if (line == NULL)
	{
		perror("Error\nfailed malloc at get_next_line");
		exit(1);
	}
	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	width = len;
	while (line)
	{
		len = 0;
		while (line[len] && line[len] != '\n')
			len++;
		free(line);
		if (len != width)
		{
			ft_printf("Error\nMap is not rectangular\n");
			close(fd);
			exit(1);
		}
		height++;
		line = get_next_line(fd);
	}
	close(fd);
	map->width = width;
	map->height = height;
	map->g_map = malloc(sizeof(char *) * height);
	if (!map->g_map)
	{
		perror("Error\nfailed malloc at find_map_size");
		exit(1);
	}
}

void	read_map(t_map *map)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(map->map_name, O_RDONLY);
	if (fd < 0)
		exit(1);
	line = "abcd"; // Initialize line to avoid uninitialized variable warning
	i = 0;
	while (i < map->height && line)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			perror("Error\nfailed malloc at get_next_line");
			exit(1);
		}
		if (line[0] == '\n') // Handle empty lines
		{
			free(line);
			map->g_map[i] = NULL;
			break ;
		}
		map->g_map[i] = line;
		i++;
	}
	close(fd);
}

// マップをコピーする関数
char	**copy_map(t_map *map)
{
	char	**map_copy;
	int		y;
	int		x;
	int		len;

	map_copy = malloc(sizeof(char *) * map->height);
	if (!map_copy)
		return (NULL);
	y = 0;
	while (y < map->height)
	{
		len = 0;
		while (map->g_map[y][len] && map->g_map[y][len] != '\n')
			len++;
		map_copy[y] = malloc(sizeof(char) * (len + 1));
		if (!map_copy[y])
		{
			while (--y >= 0)
				free(map_copy[y]);
			free(map_copy);
			return (NULL);
		}
		x = 0;
		while (x < len)
		{
			map_copy[y][x] = map->g_map[y][x];
			x++;
		}
		map_copy[y][len] = '\0';
		y++;
	}
	return (map_copy);
}

// メモリを解放する関数
void	free_map_copy(char **gmap_copy, int height)
{
	int	y;

	y = 0;
	while (y < height)
	{
		free(gmap_copy[y]);
		y++;
	}
	free(gmap_copy);
}

// フラッドフィル用の再帰関数（コピーされたマップ用）
int	flood_fill_recursive(int x, int y, t_map *map)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return (0);
	if (map->g_map_copy[y][x] == '1' || map->g_map_copy[y][x] == 'V')
		return (0);
	if (map->g_map_copy[y][x] == 'E')
		return (1);
	
	map->g_map_copy[y][x] = 'V'; // Visited mark
	
	// 4方向をチェック
	if (flood_fill_recursive(x + 1, y, map) ||
		flood_fill_recursive(x - 1, y, map) ||
		flood_fill_recursive(x, y + 1, map) ||
		flood_fill_recursive(x, y - 1, map))
		return (1);
	
	return (0);
}

void	has_valid_path(t_map *map)
{
	int		player_x;
	int		player_y;
	int		y;
	int		x;
	int		path_exists;

	// プレイヤーPの位置を探す
	player_x = -1;
	player_y = -1;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->g_map[y][x] == 'P')
			{
				player_x = x;
				player_y = y;
				break ;
			}
			x++;
		}
		if (player_x >= 0)
			break ;
		y++;
	}
	
	if (player_x < 0 || player_y < 0)
	{
		ft_printf("Error\nPlayer P not found in map\n");
		exit(1);
	}

	// マップをコピー
	map->g_map_copy = copy_map(map);
	if (!map->g_map_copy)
	{
		ft_printf("Error\nFailed to copy map for path validation\n");
		exit(1);
	}

	// フラッドフィルで出口まで到達可能かチェック
	path_exists = flood_fill_recursive(player_x, player_y, map);
	
	free_map_copy(map->g_map_copy, map->height);
	
	if (!path_exists)
	{
		ft_printf("Error\nMap must have a valid path to exit.\n");
		exit(1);
	}
}

void	has_exit_startingpos(t_map *map)
{
	int	exit_count;
	int	starting_pos_countP;
	int	starting_pos_countQ;
	int	y;
	int	x;

	exit_count = 0;
	starting_pos_countP = 0;
	starting_pos_countQ = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->g_map[y][x] == 'E')
				exit_count++;
			else if (map->g_map[y][x] == 'P')
				starting_pos_countP++;
			else if (map->g_map[y][x] == 'Q')
				starting_pos_countQ++;
			x++;
		}
		y++;
	}
	if (exit_count != 1 || starting_pos_countP != 1)
	{
		ft_printf("Error\nMap must have exactly one E,P\n");
		exit(1);
	}
}

void	is_valid_difficulty(void)
{
	if (DIFFICULTY < 1 || DIFFICULTY > 3)
	{
		ft_printf("Error\nInvalid difficulty level. Must be 1, 2, or 3.\n");
		exit(1);
	}
}

void	is_valid_fd(char *argv, t_map *map)
{
	int	fd;
	char *stdin_map;
	char directory_name[] = "./3.maps/";
	int i= 0;
	
	if(argv)
	{
		while(argv[i])
			i++;
		stdin_map = malloc(9 + i + 1);
		i=0;
		while(i<9)
		{
			stdin_map[i] = directory_name[i];
			i++;
		}
		i=0;
		while(argv[i] && argv[i] != '\n')
		{
			stdin_map[i+9] = argv[i];
			i++;
		}
		stdin_map[i+9] = '\0';
		fd = open(stdin_map, O_RDONLY);
		if (fd >= 0)
		{
			close(fd);
			map->map_name = stdin_map;
			return ;
		}
	}
	write(2, "failed to open map file from stdin.\n", 36);
	fd = open(MAP_FILES, O_RDONLY);
	if (fd >= 0)
	{
		close(fd);
		map->map_name = MAP_FILES;
		return ;
	}
	perror("Error\nFailed to open map file");
	exit(1);
}

void	map_is_invalid(t_map *map)
{
	if (!map)
	{
		perror("Error\nMap is NULL");
		exit(1);
	}
	if (map->width <= 0 || map->height <= 0)
	{
		perror("Error\nInvalid map dimensions");
		exit(1);
	}
	if (!map->g_map)
	{
		perror("Error\nMap data is NULL");
		exit(1);
	}
}

void	maperror(t_map *map)
{
	find_map_size(map);
	read_map(map);
	// is_valid_fd();
	is_valid_difficulty();
	map_is_invalid(map);
	has_exit_startingpos(map);
	has_1collectible(map);
	is_sorrounded_by_walls(map);
	has_valid_path(map);
}

int	difficulty_var(int variable)
{
	if (variable == 1)
	{
		if (DIFFICULTY == 1)
			return (30); // Easy
		else if (DIFFICULTY == 2)
			return (22); // Normal
		else if (DIFFICULTY == 3)
			return (15); // Hard
		else
			exit(1); // Invalid difficulty
	}
	else if (variable == 2)
	{
		if (DIFFICULTY == 1)
			return (8); // Easy
		else if (DIFFICULTY == 2)
			return (4); // Normal
		else if (DIFFICULTY == 3)
			return (1); // Hard
		else
			exit(1); // Invalid difficulty
	}
	else
		exit(1);
}

// 敵キャラ全部を初期化
void	init_enemies(t_map *map)
{
	int		y;
	int		x;
	int		n;
	char	c;

	n = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			c = map->g_map[y][x];
			if ((c == 'W' || c == 'X' || c == 'Y' || c == 'Z')
				&& n < MAX_ENEMIES)
			{
				map->enemies[n].x = x;
				map->enemies[n].y = y;
				map->enemies[n].dir = -1; // 初期は左向き
				if (c == 'W')
					map->enemies[n].speed = CPU_SPEED * (7 + difficulty_var(2));
				else if (c == 'X')
					map->enemies[n].speed = CPU_SPEED * (4 + difficulty_var(2));
				else if (c == 'Y')
					map->enemies[n].speed = CPU_SPEED * (3 + difficulty_var(2)
							/ 2);
				else if (c == 'Z')
					map->enemies[n].speed = CPU_SPEED * (0 + difficulty_var(2)
							/ 3);
				else
					map->enemies[n].speed = 0; // デフォルト速度
				map->enemies[n].frame = 0;
				map->enemies[n].symbol = c;
				n++;
			}
			x++;
		}
		y++;
	}
	map->enemy_count = n;
}

// 敵キャラ1体を動かす
void	move_enemy(t_map *map, t_enemy *enemy)
{
	int	nx;
	int	ny;

	enemy->frame++;
	if (enemy->frame < enemy->speed)
		return ;
	enemy->frame = 0;
	nx = enemy->x + enemy->dir;
	ny = enemy->y;
	if (nx < 0 || nx >= map->width || map->g_map[ny][nx] == '1')
	{
		enemy->dir *= -1;
		nx = enemy->x + enemy->dir;
		if (nx < 0 || nx >= map->width || map->g_map[ny][nx] == '1')
			return ;
	}
	// --- ここを修正 ---
	if (map->g_map[ny][nx] == 'P')
	{
		map->player1_loses = 1;
		map->timer_enabled = 0;
		return ;
	}
	if (map->g_map[ny][nx] == 'Q')
	{
		map->player2_loses = 1;
		map->timer_enabled = 0;
		return ;
	}
	// -----------------
	// 元の位置を消すのも、プレイヤーがいなければ
	if (map->g_map[enemy->y][enemy->x] == enemy->symbol)
		map->g_map[enemy->y][enemy->x] = '0';
	map->g_map[ny][nx] = enemy->symbol;
	enemy->x = nx;
	enemy->y = ny;
}

void	move_all_enemies(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->enemy_count)
	{
		move_enemy(map, &map->enemies[i]);
		i++;
	}
}

static void	draw_tile(void *mlx, void *win, int x, int y, char c, t_map *map)
{
	int	i;
	int	j;

	if (c == '1' && map->wall_img)
		mlx_put_image_to_window(mlx, win, map->wall_img, x * TILE, y * TILE);
	else if (c == '0' && map->empty_img)
		mlx_put_image_to_window(mlx, win, map->empty_img, x * TILE, y * TILE);
	else if (c == 'C' && map->collect_img)
		mlx_put_image_to_window(mlx, win, map->collect_img, x * TILE, y * TILE);
	else if (c == 'E' && map->exit_img)
		mlx_put_image_to_window(mlx, win, map->exit_img, x * TILE, y * TILE);
	else if ((c == 'W' || c == 'X' || c == 'Y' || c == 'Z') && map->enemy_img)
		mlx_put_image_to_window(mlx, win, map->enemy_img, x * TILE, y * TILE);
	else if (c == 'P')
	{
		if (map->player1_dir == 0 && map->player1_img_left)
			mlx_put_image_to_window(mlx, win, map->player1_img_left, x * TILE, y
				* TILE);
		else if (map->player1_dir == 1 && map->player1_img_right)
			mlx_put_image_to_window(mlx, win, map->player1_img_right, x * TILE,
				y * TILE);
		else if (map->player1_dir == 2 && map->player1_img_up)
			mlx_put_image_to_window(mlx, win, map->player1_img_up, x * TILE, y
				* TILE);
		else if (map->player1_dir == 3 && map->player1_img_down)
			mlx_put_image_to_window(mlx, win, map->player1_img_down, x * TILE, y
				* TILE);
	}
	else if (c == 'Q')
	{
		if (map->player2_dir == 0 && map->player2_img_left)
			mlx_put_image_to_window(mlx, win, map->player2_img_left, x * TILE, y
				* TILE);
		else if (map->player2_dir == 1 && map->player2_img_right)
			mlx_put_image_to_window(mlx, win, map->player2_img_right, x * TILE,
				y * TILE);
		else if (map->player2_dir == 2 && map->player2_img_up)
			mlx_put_image_to_window(mlx, win, map->player2_img_up, x * TILE, y
				* TILE);
		else if (map->player2_dir == 3 && map->player2_img_down)
			mlx_put_image_to_window(mlx, win, map->player2_img_down, x * TILE, y
				* TILE);
	}
	else
	{
		// fallback: magenta
		i = 0;
		while (i < TILE)
		{
			j = 0;
			while (j < TILE)
			{
				mlx_pixel_put(mlx, win, x * TILE + i, y * TILE + j, 0xFF00FF);
				j++;
			}
			i++;
		}
	}
}

void	draw_win_screen(void *mlx, void *win, const char *msg, int color)
{
	int x, y;
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

void	ft_putnbr_mlx(int n, void *mlx, void *win, int x, int y)
{
	char	buf[12];
	int		i;
	int		num;
	int		sign;

	i = 11;
	buf[i--] = '\0';
	sign = (n < 0);
	num = n;
	if (n == 0)
		buf[i--] = '0';
	if (n < 0)
		num = -n;
	while (num > 0)
	{
		buf[i--] = '0' + (num % 10);
		num /= 10;
	}
	if (sign)
		buf[i--] = '-';
	mlx_string_put(mlx, win, x, y, 0x000000, &buf[i + 1]);
}

void	draw_map(t_map *map)
{
	if (map->player1_wins)
	{
		draw_win_screen(map->mlx, map->win, "player1 wins", 0xFF2222);
		return ;
	}
	if (map->player2_wins)
	{
		draw_win_screen(map->mlx, map->win, "player2 wins", 0x2222FF);
		return ;
	}
	if (map->player1_loses)
	{
		draw_win_screen(map->mlx, map->win, "player1 loses", 0x2222FF);
		return ;
	}
	if (map->player2_loses)
	{
		draw_win_screen(map->mlx, map->win, "player2 loses", 0xFF2222);
		return ;
	}
	int x, y, map_y;
	if (!map || !map->g_map)
		return ;
	y = 0;
	while (y < VIEW_H && (map->view_offset_y + y) < map->height)
	{
		x = 1;
		map_y = map->view_offset_y + y;
		while (x < VIEW_W + 1 && x < map->width)
		{
			if (map->g_map[map_y])
				draw_tile(map->mlx, map->win, x - 1, y, map->g_map[map_y][x],
					map);
			x++;
		}
		y++;
		// printf("Drawing row %d\n", y);
	};
	// if (map->show_moves > 0)
	// {
	mlx_string_put(map->mlx, map->win, 10, 20, 0x000000, "moves:");
	ft_putnbr_mlx(map->player1_moves, map->mlx, map->win, 50, 20);
	//     map->show_moves=0; // 1回だけ表示したらOFF
	// }
}

// int	scroll_map(void *param)
// {
// 	static struct s_timeval	last = {0};
// 	struct s_timeval		now;
// 	t_map					*map;
// 	void					**ctx;
// 	void					*mlx;
// 	void					*win;

// 	ctx = (void **)param;
// 	map = (t_map *)ctx[0];
// 	mlx = ctx[1];
// 	win = ctx[2];
// 	ft_gettimeofday(&now, NULL);
// 	if (last.tv_sec == 0)
// 		last = now;
// 	if (now.tv_sec - last.tv_sec >= 5)
// 	{
// 		if (map->view_offset_y > 0)
// 			map->view_offset_y--;
// 		draw_map(mlx, win, map);
// 		last = now;
// 	}
// 	return (0);
// }

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

// int	esc_key(int keycode, void *param)
// {
//     (void)param;
//     if (keycode == 65307)
//         exit(0);
//     return (0);
// }
// プレイヤー初期位置を探す
void	find_players(t_map *map)
{
	int	y;
	int	x;
	int	found_p;
	int	found_q;

	found_p = 0;
	found_q = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (!found_p && map->g_map[y][x] == 'P')
			{
				map->player1_x = x;
				map->player1_y = y;
				found_p = 1;
			}
			else if (!found_q && map->g_map[y][x] == 'Q')
			{
				map->player2_x = x;
				map->player2_y = y;
				found_q = 1;
			}
			if (found_p && found_q)
				return ;
			x++;
		}
		y++;
	}
	if (!found_p)
	{
		perror("Error\nPlayer P not found in map");
		exit(1);
	}
	// Qがいなければ無効値をセット
	if (!found_q)
	{
		map->player2_x = -1;
		map->player2_y = -1;
	}
}

int	is_enemy_tile(char c)
{
	return (c == 'W' || c == 'X' || c == 'Y' || c == 'Z');
}

void	check_player_enemy_collision(t_map *map)
{
	if (is_enemy_tile(map->g_map[map->player1_y][map->player1_x]))
	{
		map->player1_loses = 1;
		map->timer_enabled = 0;
	}
	else if (map->player2_x >= 0 && map->player2_y >= 0
		&& is_enemy_tile(map->g_map[map->player2_y][map->player2_x]))
	{
		map->player2_loses = 1;
		map->timer_enabled = 0;
	}
}

void	check_player_out_of_screen(t_map *map)
{
	int	p1_screen_y;
	int	p2_screen_y;

	p1_screen_y = map->player1_y - map->view_offset_y;
	p2_screen_y = map->player2_y - map->view_offset_y;
	if (p1_screen_y >= VIEW_H)
	{
		map->player1_loses = 1;
		map->timer_enabled = 0;
	}
	else if (map->player2_x >= 0 && map->player2_y >= 0
		&& p2_screen_y >= VIEW_H)
	{
		map->player2_loses = 1;
		map->timer_enabled = 0;
	}
}

int collect_all_collectibles(t_map *map)
{
	int	y;
	int	x;

	if(MODE_COLLECTABLES == 0)
		return(1); 
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->g_map[y][x] == 'C')
			{
				return(0); 
			}
			x++;
		}
		y++;
	}
	return(1);
}

// プレイヤー移動（キャラ, dx, dy, map, 相手座標）
void	move_player(t_map *map, char who, int dx, int dy)
{
	int	nx;
	int	ny;

	int *px, *py, ox, oy;
	char mark, other;
	if (who == 'P')
	{
		map->player1_moves++;
		map->show_moves = 1; // 動いたら表示フラグON
		ft_printf("player1 moves: %d\n", map->player1_moves);
		px = &map->player1_x;
		py = &map->player1_y;
		ox = map->player2_x;
		oy = map->player2_y;
		mark = 'P';
		other = 'Q';
		if (dx > 0)
			map->player1_dir = 1; // 右
		else if (dx < 0)
			map->player1_dir = 0; // 左
		else if (dy < 0)
			map->player1_dir = 2; // 上
		else if (dy > 0)
			map->player1_dir = 3; // 下
	}
	else
	{
		px = &map->player2_x;
		py = &map->player2_y;
		ox = map->player1_x;
		oy = map->player1_y;
		mark = 'Q';
		other = 'P';
		if (dx > 0)
			map->player2_dir = 1;
		else if (dx < 0)
			map->player2_dir = 0;
		else if (dy < 0)
			map->player2_dir = 2;
		else if (dy > 0)
			map->player2_dir = 3;
		// Qがいない場合は何もしない
		if (*px < 0 || *py < 0 || map->g_map[*py][*px] != 'Q')
			return ;
	}
	nx = *px + dx;
	ny = *py + dy;
	if (nx < 0 || nx >= map->width || ny < 0 || ny >= map->height)
		return ;
	if (is_enemy_tile(map->g_map[ny][nx]))
	{
		if (who == 'P')
		{
			map->player1_loses = 1;
			map->timer_enabled = 0;
		}
		else
		{
			map->player2_loses = 1;
			map->timer_enabled = 0;
		}
		return ;
	}
	if (map->g_map[ny][nx] == '1' || (nx == ox && ny == oy))
		return ;
	if (who == 'P' && map->g_map[ny][nx] == 'E')
	{
		if(collect_all_collectibles(map) == 1)
		{
			map->player1_wins = 1;
		}
		return ;
	}
	if (who == 'Q' && map->g_map[ny][nx] == 'E')
	{
		map->player2_wins = 1;
		return ;
	}
	if (map->g_map[*py][*px] == mark)
		map->g_map[*py][*px] = '0';
	else if (map->g_map[*py][*px] == other)
		map->g_map[*py][*px] = other;
	map->g_map[ny][nx] = mark;
	*px = nx;
	*py = ny;
}

// キー入力
int	wasd_jyuji_key(int keycode, t_map *map)
{
	// プレイヤー1: wasd
	if (keycode == 'w')
		move_player(map, 'P', 0, -1);
	else if (keycode == 's')
		move_player(map, 'P', 0, 1);
	else if (keycode == 'a')
		move_player(map, 'P', -1, 0);
	else if (keycode == 'd')
		move_player(map, 'P', 1, 0);
	// プレイヤー2: jyuji
	else if (keycode == 65362 || keycode == 'i')
		move_player(map, 'Q', 0, -1);
	else if (keycode == 65364 || keycode == 'k')
		move_player(map, 'Q', 0, 1);
	else if (keycode == 65361 || keycode == 'j')
		move_player(map, 'Q', -1, 0);
	else if (keycode == 65363 || keycode == 'l')
		move_player(map, 'Q', 1, 0);
	else if (keycode == 65307)
		exit(0);
	draw_map(map);
	return (0);
}

int	nakami(t_map map)
{
	int img_w, img_h;

	map.player1_loses = 0;
	map.player2_loses = 0;
	map.player1_wins = 0;
	map.player2_wins = 0;
	map.player1_moves = 0;
	map.player1_moves = 0;
	map.last_player1_moves = 0;
	map.show_moves = 0;
	map.tm = init_timer(60);
	map.timer_enabled = 1;
	find_players(&map);
	map.player1_dir = 3; // 下向き（down）で初期化
	map.player2_dir = 3;
	init_enemies(&map);
	map.view_offset_y = map.height - VIEW_H;
	if (map.view_offset_y < 0)
		map.view_offset_y = 0;

	// 画像を読み込んでmapに格納
	map.player1_img_left = mlx_xpm_file_to_image(map.mlx,
			"2.textures/player1_left.xpm", &img_w, &img_h);
	map.player1_img_right = mlx_xpm_file_to_image(map.mlx,
			"2.textures/player1_right.xpm", &img_w, &img_h);
	map.player1_img_up = mlx_xpm_file_to_image(map.mlx,
			"2.textures/player1_up.xpm", &img_w, &img_h);
	map.player1_img_down = mlx_xpm_file_to_image(map.mlx,
			"2.textures/player1_down.xpm", &img_w, &img_h);

	map.player2_img_left = mlx_xpm_file_to_image(map.mlx,
			"2.textures/player2_left.xpm", &img_w, &img_h);
	map.player2_img_right = mlx_xpm_file_to_image(map.mlx,
			"2.textures/player2_right.xpm", &img_w, &img_h);
	map.player2_img_up = mlx_xpm_file_to_image(map.mlx,
			"2.textures/player2_up.xpm", &img_w, &img_h);
	map.player2_img_down = mlx_xpm_file_to_image(map.mlx,
			"2.textures/player2_down.xpm", &img_w, &img_h);

	map.wall_img = mlx_xpm_file_to_image(map.mlx, "2.textures/wall.xpm", &img_w,
			&img_h);
	map.empty_img = mlx_xpm_file_to_image(map.mlx, "2.textures/empty.xpm",
			&img_w, &img_h);
	map.collect_img = mlx_xpm_file_to_image(map.mlx, "2.textures/collect.xpm",
			&img_w, &img_h);
	map.exit_img = mlx_xpm_file_to_image(map.mlx, "2.textures/exit.xpm", &img_w,
			&img_h);
	map.enemy_img = mlx_xpm_file_to_image(map.mlx, "2.textures/enemy.xpm",
			&img_w, &img_h);

	map.win = mlx_new_window(map.mlx, VIEW_W * TILE, VIEW_H * TILE, "ATAOKA");
	mlx_hook(map.win, 17, 0, close_window, NULL);
	mlx_hook(map.win, 2, 1L << 0, wasd_jyuji_key, &map);
	mlx_loop_hook(map.mlx, timer_hook, &map);
	draw_map(&map);
	mlx_loop(map.mlx);
	return (1);
}