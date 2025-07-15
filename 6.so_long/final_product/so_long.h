#ifndef SO_LONG_H
# define SO_LONG_H

# define CPU_SPEED 10
# define TILE 50
# define VIEW_W 16
# define VIEW_H 14
# define MAX_ENEMIES 128
# define MAP_FILES "3.maps/test1.ber"
# define DIFFICULTY 3        // 1:easy, 2:normal, 3:hard
# define MODE_COLLECTABLES 0 // 1:ON, 0:OFF

# include "1.srcs/get_next_line/get_next_line.h"
# include "1.srcs/minilibx-linux/mlx.h"
# include "1.srcs/printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_timeval
{
	long tv_sec;           /* 秒 */
	long tv_usec;          /* マイクロ秒 */
	long long frame_count; /* 経過フレーム数 */
	int frame_dt_us;       /* 1 フレームあたりの µs (例: 1000000/60) */
}				t_timeval;

typedef struct s_enemy
{
	int			x;
	int			y;
	int dir;     // -1:左, 1:右
	int speed;   // 何フレームごとに動くか
	int frame;   // 現在のフレームカウント
	char symbol; // マップ上の記号（例: 'D', 'E', 'F', 'G'など）
}				t_enemy;

typedef struct s_player_data
{
	char		who;
	int			dx;
	int			dy;
	int			*px;
	int			*py;
	int			ox;
	int			oy;
	char		mark;
	char		other;
}				t_player_data;

typedef struct s_map
{
	int			width;
	int			height;
	char		*map_name;
	char		**g_map;
	char		**g_map_copy;
	void		*mlx;
	void		*win;
	t_timeval	*tm;
	int			stdin_or_header;
	int			player1_x;
	int			player1_y;
	int			player2_x;
	int			player2_y;
	int			view_offset_y;
	int key_pressed;              // 長押し禁止フラグ
	int timer_enabled;            // 1:動作, 0:停止
	t_enemy enemies[MAX_ENEMIES]; // 敵を最大128体まで配列で管理
	int enemy_count;              // 現在の敵の数
	int			player1_loses;
	int			player2_loses;
	int			player1_wins;
	int			player2_wins;
	// プレイヤー1画像
	void		*player1_img_left;
	void		*player1_img_right;
	void		*player1_img_up;
	void		*player1_img_down;
	// プレイヤー2画像
	void		*player2_img_left;
	void		*player2_img_right;
	void		*player2_img_up;
	void		*player2_img_down;
	// その他
	void		*wall_img;
	void		*empty_img;
	void		*collect_img;
	void		*exit_img;
	void		*enemy_img;
	// 勝敗画像
	void		*player1_wins_img;
	void		*player2_wins_img;
	void		*player1_loses_img;
	void		*player2_loses_img;
	// プレイヤーの向き
	int player1_dir; // 0:left, 1:right, 2:up, 3:down
	int			player2_dir;
	int player1_moves;      // プレイヤー1の移動回数
	int last_player1_moves; // 前回表示したカウント
	int show_moves;         // 1なら表示、0なら非表示

}				t_map;

// typedef struct s_timer
// {
// 	long	frame_count;   /* 経過フレーム数 */
// 	int		frame_dt_us;   /* 1 フレームあたりの µs (例: 1000000/60) */
// }               t_timer;

/*
** 60fps なら frame_dt_us = 1000000 / 60 ≒ 16666
*/

// Function prototypes
void			stdin_error_check(int argc, char **argv, t_map *map);
int				main(int argc, char **argv);
t_timeval		*init_timer(int fps);
int				ft_gettimeofday(t_timeval *tm, t_timeval *tv);
int				timer_hook(void *param);
void			is_sorrounded_by_walls(t_map *map);
void			has_1collectible(t_map *map);
void			find_map_size(t_map *map);
int				open_map_file(t_map *map);
int				get_map_width(int fd, t_map *map);
int				validate_map_rectangle(int fd, int width, t_map *map);
void			setup_map_structure(t_map *map, int width, int height);
int				open_and_free(t_map *map);
void			read_map(t_map *map);
char			**copy_map(t_map *map);
void			free_map_copy(char **gmap_copy, int height);
int				flood_fill_recursive(int x, int y, t_map *map);
void			has_valid_path(t_map *map);
void			has_exit_startingpos(t_map *map);
void			is_valid_difficulty(void);
void			is_valid_fd(char *argv, t_map *map);
void			map_is_invalid(t_map *map);
void			maperror(t_map *map);
int				difficulty_var(int variable);
void			init_enemies(t_map *map);
void			move_enemy(t_map *map, t_enemy *enemy);
void			move_all_enemies(t_map *map);
void			draw_tile(int x, int y, char c, t_map *map);
void			draw_win_screen(void *mlx, void *win, const char *msg,
					int color);
void			ft_putnbr_mlx(int n, t_map *map, int x, int y);
void			draw_map(t_map *map);
void			load_game_result_images(t_map *map);
void			draw_game_result_screen(t_map *map);
int				close_window(void *param);
void			find_players(t_map *map);
int				is_enemy_tile(char c);
void			check_player_enemy_collision(t_map *map);
void			check_player_out_of_screen(t_map *map);
int				collect_all_collectibles(t_map *map);
void			move_player(t_map *map, char who, int dx, int dy);
void			setup_player1_data(t_map *map, t_player_data *pd, int dx,
					int dy);
void			setup_player2_data(t_map *map, t_player_data *pd, int dx,
					int dy);
void			setup_player_data(t_map *map, t_player_data *pd, int dx,
					int dy);
int				check_basic_collision(t_map *map, t_player_data *pd, int nx,
					int ny);
int				check_enemy_collision(t_map *map, t_player_data *pd, int nx,
					int ny);
int				check_movement_validity(t_map *map, t_player_data *pd, int nx,
					int ny);
int				check_exit_conditions(t_map *map, t_player_data *pd, int nx,
					int ny);
void			update_player_position(t_map *map, t_player_data *pd, int nx,
					int ny);
int				wasd_jyuji_key(int keycode, t_map *map);
int				nakami(t_map map);

// # include <stdlib.h>
// # include <time.h>

// void *mymalloc(size_t size);
// void myfree(void *ptr);

#endif