CC      := gcc
CFLAGS  := -Wall -Werror -Wextra -no-pie -g -fsanitize=address
INCLUDES:= -Iminilibx-linux -I1.srcs/get_next_line -I1.srcs/printf

# Individual function files
FUNC_SRC := 1.srcs/functions/1.main.c \
            1.srcs/functions/2.stdin_error_check.c \
            1.srcs/functions/3.init_timer.c \
            1.srcs/functions/4.ft_gettimeofday.c \
            1.srcs/functions/5.timer_hook.c \
            1.srcs/functions/6.setup_map_structure.c \
            1.srcs/functions/7.is_sorrounded_by_walls.c \
            1.srcs/functions/8.has_1collectible.c \
            1.srcs/functions/9.find_map_size.c \
            1.srcs/functions/10.read_map.c \
            1.srcs/functions/11.copy_map.c \
            1.srcs/functions/12.free_map_copy.c \
            1.srcs/functions/13.flood_fill_recursive.c \
            1.srcs/functions/14.has_valid_path.c \
            1.srcs/functions/15.has_exit_startingpos.c \
            1.srcs/functions/16.is_valid_difficulty.c \
            1.srcs/functions/17.is_valid_fd.c \
            1.srcs/functions/18.map_is_invalid.c \
            1.srcs/functions/19.maperror.c \
            1.srcs/functions/20.difficulty_var.c \
            1.srcs/functions/21.init_enemies.c \
            1.srcs/functions/22.move_enemy.c \
            1.srcs/functions/23.move_all_enemies.c \
            1.srcs/functions/24.draw_tile.c \
            1.srcs/functions/25.draw_win_screen.c \
            1.srcs/functions/26.ft_putnbr_mlx.c \
            1.srcs/functions/27.draw_map.c \
            1.srcs/functions/28.close_window.c \
            1.srcs/functions/29.find_players.c \
            1.srcs/functions/30.is_enemy_tile.c \
            1.srcs/functions/31.check_player_enemy_collision.c \
            1.srcs/functions/32.check_player_out_of_screen.c \
            1.srcs/functions/33.collect_all_collectibles.c \
            1.srcs/functions/34.move_player.c \
            1.srcs/functions/35.wasd_jyuji_key.c \
            1.srcs/functions/36.nakami.c \
            1.srcs/functions/37.open_map_file.c \
            1.srcs/functions/38.get_map_width.c \
            1.srcs/functions/39.validate_map_rectangle.c \
            1.srcs/functions/40.update_player_position.c \
            1.srcs/functions/41.setup_player1_data.c \
            1.srcs/functions/42.setup_player2_data.c \
            1.srcs/functions/43.setup_player_data.c \
            1.srcs/functions/44.check_basic_collision.c \
            1.srcs/functions/45.check_enemy_collision.c \
            1.srcs/functions/46.check_movement_validity.c \
            1.srcs/functions/47.check_exit_conditions.c \
            1.srcs/functions/48.validate_map_characters.c \
            1.srcs/functions/49.load_game_result_images.c \
            1.srcs/functions/50.draw_game_result_screen.c \
            1.srcs/functions/51.validate_player_count.c \
            1.srcs/functions/52.flood_fill_with_collectibles.c

# Supporting library files
LIB_SRC := 1.srcs/get_next_line/get_next_line.c \
           1.srcs/get_next_line/get_next_line_utils.c \
           1.srcs/get_next_line/get_next_line_reset.c \
           1.srcs/printf/ft_printf.c \
           1.srcs/printf/ft_printf_utils.c

SRC     := $(FUNC_SRC) $(LIB_SRC)
OBJ     := $(SRC:.c=.o)

MLX_DIR := 1.srcs/minilibx-linux
MLX_LIB := $(MLX_DIR)/libmlx_Linux.a

NAME    := so_long

all: $(NAME)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ) $(MLX_LIB)
	xset -r
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJ) $(MLX_LIB) -lX11 -lXext
	@echo "Run ./$(NAME) to test."

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	xset r
	rm -f $(NAME)

re: fclean all
	xset -r

.PHONY: all clean fclean