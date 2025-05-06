#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int size;
int **grid;  // 盤面
int *clues; // 外周のヒント（上・下・左・右）

int ft_strlen(char *str){
	char *ptr = str;
	while (*ptr)
		ptr++;
	return (ptr - str);
}

//入力の文字列をint配列に変換する
//ex ... "4 3 2 ... 1" -> {4, 3, 2, ..., 1}
void input_to_clues(char *str){
	int i = 0;
	int len = ft_strlen(str);
	if (len % 8 != 7)
	{
		printf("無効な入力形式\n");
		return ;
	}
	size = (len + 1) / 8;
	clues = (int *)malloc(sizeof(int) * (4 * size));
	while (i < len){
		if (i % 2 == 0){
			if (str[i] < '1' || str[i] > ('0' + size)){
				printf("無効なヒントの値: %c\n", str[i]);
				free(clues);
				return ;
			}
			clues[i / 2] = str[i] - '0';
		}
		else if (str[i] != ' '){
			printf("無効な入力形式\n");
			free(clues);
			return ;
		}
		i++;
	}
}

// ビルの見える数を数える
int count_visible_buildings(int *line) {
    int max_height = 0;
	int count = 0;
	int i = 0;
    while (i < size) {
        if (line[i] > max_height) {
            max_height = line[i];
            count++;
        }
        i++;
    }
    return count;
}
// 数字を配置できるか判定
int is_valid_placement(int row, int col, int num) {
    int i = 0;
    while (i < size) {
        if (grid[row][i] == num || grid[i][col] == num)
            return (0);
        i++;
    }

    // ヒントと矛盾する場合は無駄な探索を防ぐ
    grid[row][col] = num;

    if ((row == size - 1 && clues[col] && count_visible_buildings(grid[col]) != clues[col]) ||
        (col == size - 1 && clues[2 * size + row] && count_visible_buildings(grid[row]) != clues[2 * size + row])) {
        grid[row][col] = 0;
        return (0);
    }

    grid[row][col] = 0;
    return (1);
}

// 現在の盤面がヒントを満たしているかチェック
int check_clues() {
    int *line = (int *)malloc(sizeof(int) * size);
	if (!line){
		printf("メモリ確保に失敗しました");
		return (0);
	}
    int col = 0;
	int row = 0;



    // 上
    while (col < size) {
        int i = 0;
        while (i < size) {
            line[i] = grid[i][col];
            i++;
        }
        if (clues[col] && count_visible_buildings(line) != clues[col])
		{
            free(line);
			return (0);
		}
        col++;
    }

    // 下
    col = 0;
    while (col < size) {
        int i = 0;
        while (i < size) {
            line[i] = grid[size - 1 - i][col];
            i++;
        }
        if (clues[size + col] && count_visible_buildings(line) != clues[size + col]){
			free(line);
            return (0);
		}
        col++;
    }

    // 左
    row = 0;
    while (row < size) {
        int i = 0;
        while (i < size) {
            line[i] = grid[row][i];
            i++;
        }
        if (clues[2 * size + row] && count_visible_buildings(line) != clues[2 * size + row]){
			free(line);
            return (0);
		}
        row++;
    }

    // 右
    row = 0;
    while (row < size) {
        int i = 0;
        while (i < size) {
            line[i] = grid[row][size - 1 - i];
            i++;
        }
        if (clues[3 * size + row] && count_visible_buildings(line) != clues[3 * size + row])
		{
			free(line);
            return (0);
		}
        row++;
    }
	free(line);
    return (1);
}

// 再帰的にバックトラッキングで探索
int solve(int row, int col) {
    if (row == size) {
        return (check_clues()); // すべて埋めたらヒントを確認
    }
	int next_row;
	int next_col;
	int num;

	if (col == size - 1){
		next_row = row + 1;
		next_col = 0;
	}
	else{
		next_row = row;
		next_col = col + 1;
	}

	num = 1;
    while (num <= size) {
        if (is_valid_placement(row, col, num)) {
            grid[row][col] = num;

            // 部分的にヒントが合っているかチェック
            if ((col == size - 1 && clues[2 * size + row] && count_visible_buildings(grid[row]) != clues[2 * size + row]) ||
                (row == size - 1 && clues[col] && count_visible_buildings(grid[col]) != clues[col])) {
                grid[row][col] = 0;  // 戻す
            } else if (solve(next_row, next_col)) {
                return (1);
            }

            grid[row][col] = 0;
        }
        num++;
    }

    return (0);
}

// 盤面を表示
void print_grid() {
    int i = 0, j = 0;
    while (i < size) {
        j = 0;
        while (j < size) {
            printf("%d ", grid[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

// メイン関数
int main(int argc, char *argv[]) {

	//エラーハンドリングはこの辺に
	if (argc != 2) {
        printf("使用方法: %s \"ヒント\"\n", argv[0]);
        return 1;
    }
	input_to_clues(argv[1]);
	if (!clues) {
        printf("無効な入力形式\n");
        return 1;
    }
	grid = (int **)malloc(size * sizeof(int *));
	if(!grid){
		printf("メモリ確保に失敗しました");
		free(clues);
		return (1);
	}
    int i = 0;
	int j = 0;
    while (i < size) {
		grid[i] = (int *)malloc(sizeof(int) * size);
		if (!grid[i]){
			printf("メモリ確保に失敗しました");
			while (i--)
				free(grid[i]);
			free(grid);
			free(clues);
			return (1);
		}
        j = 0;
        while (j < size) {
            grid[i][j] = 0;
            j++;
        }
        i++;
    }

    if (solve(0, 0)) {
        printf("解:\n");
        print_grid();
    } else {
        printf("解が見つかりませんでした。\n");
    }

    i = 0;
    while (i < size)
		free(grid[i++]);

    free(grid);
    free(clues);

    return 0;
}
