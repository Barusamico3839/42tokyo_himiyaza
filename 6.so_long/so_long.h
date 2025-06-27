

#ifndef SO_LONG_H
# define SO_LONG_H

# define CPU_SPEED 10
# define TILE 50
# define VIEW_W 16
# define VIEW_H 14
# define MAX_ENEMIES 128
# define MAP_FILES "3.maps/2p.ber"
# define DIFFICULTY 2 // 1:easy, 2:normal, 3:hard

# include "1.srcs/get_next_line/get_next_line.h"
# include "1.srcs/minilibx-linux/mlx.h"
# include "1.srcs/minilibx-linux/mlx_int.h"
# include "1.srcs/printf/ft_printf.h"
# include <X11/Xlib.h>
# include <X11/extensions/XShm.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <unistd.h>

typedef struct s_timeval
{
	long tv_sec;           /* 秒 */
	long tv_usec;          /* マイクロ秒 */
	long long frame_count; /* 経過フレーム数 */
	int frame_dt_us;       /* 1 フレームあたりの µs (例: 1000000/60) */
}			t_timeval;

typedef struct s_enemy
{
	int		x;
	int		y;
	int dir;     // -1:左, 1:右
	int speed;   // 何フレームごとに動くか
	int frame;   // 現在のフレームカウント
	char symbol; // マップ上の記号（例: 'D', 'E', 'F', 'G'など）
}			t_enemy;

typedef struct s_map
{
	int		width;
	int		height;
	char	**g_map;
	void	*mlx;
	void	*win;
	t_timeval	*tm;
	int		player1_x;
	int		player1_y;
	int		player2_x;
	int		player2_y;
	int		view_offset_y;
	int key_pressed;              // 長押し禁止フラグ
	int timer_enabled;            // 1:動作, 0:停止
	t_enemy enemies[MAX_ENEMIES]; // 敵を最大128体まで配列で管理
	int enemy_count;              // 現在の敵の数
	int		player1_loses;
	int		player2_loses;
	int		player1_wins;
	int		player2_wins;
	// プレイヤー1画像
	void	*player1_img_left;
	void	*player1_img_right;
	void	*player1_img_up;
	void	*player1_img_down;
	// プレイヤー2画像
	void	*player2_img_left;
	void	*player2_img_right;
	void	*player2_img_up;
	void	*player2_img_down;
	// その他
	void	*wall_img;
	void	*empty_img;
	void	*collect_img;
	void	*exit_img;
	void	*enemy_img;
	// プレイヤーの向き
	int player1_dir; // 0:left, 1:right, 2:up, 3:down
	int		player2_dir;
	int player1_moves; // プレイヤー1の移動回数
	int last_player1_moves; // 前回表示したカウント
    int show_moves;         // 1なら表示、0なら非表示

}			t_map;



// typedef struct s_timer
// {
// 	long	frame_count;   /* 経過フレーム数 */
// 	int		frame_dt_us;   /* 1 フレームあたりの µs (例: 1000000/60) */
// }               t_timer;

/*
** 60fps なら frame_dt_us = 1000000 / 60 ≒ 16666
*/
t_timeval	*init_timer(int fps);
int			timer_hook(void *param);
int			ft_gettimeofday(t_timeval *tm, t_timeval *tv);

int			difficulty_var(int variable);
void		check_player_enemy_collision(t_map *map);
void		move_all_enemies(t_map *map);
void		check_player_out_of_screen(t_map *map);
void		draw_map(t_map *map);
int			nakami(void *mlx);

void		*my_malloc(size_t size);

#endif