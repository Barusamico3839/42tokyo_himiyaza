#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int		size;
int **grid; // 盤面
int *clues; // 外周のヒント（上・下・左・右）
int		*seen;

int	ft_strlen(char *str)
{
	char	*ptr;

	ptr = str;
	while (*ptr)
		ptr++;
	return (ptr - str);
}

void	init_seen(void)
{
	int	i;

	seen = (int *)malloc(sizeof(int) * size * 2);
	i = 0;
	while (i < (size * 2))
		seen[i++] = 0;
}

//入力の文字列をint配列に変換する
// ex ... "4 3 2 ... 1" -> {4, 3, 2, ..., 1}
void	input_to_clues(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (len % 8 != 7)
	{
		printf("Error\n, 無効な入力形式\n");
		return ;
	}
	size = (len + 1) / 8;
	clues = (int *)malloc(sizeof(int) * (4 * size));
	if (!clues)
	{
		printf("メモリ確保に失敗しました");
		return ;
	}
	while (i < len)
	{
		if (i % 2 == 0)
		{
			if (str[i] < '1' || str[i] > ('0' + size))
			{
				printf("無効なヒントの値: %c\n", str[i]);
				free(clues);
				return ;
			}
			clues[i / 2] = str[i] - '0';
		}
		else if (str[i] != ' ')
		{
			printf("無効な入力形式\n");
			free(clues);
			return ;
		}
		i++;
	}
}

// `index` を使ってビルの見える数を数える
int	count_visible_buildings_up(int col)
{
	int	cur_max;
	int	count;
	int	i;

	cur_max = 0;
	count = 0;
	i = 0;
	while (i < size)
	{
		if (grid[i][col] > cur_max)
		{
			cur_max = grid[i][col];
			count++;
		}
		if (grid[i][col] == size)
			return (count);
		if (i < size - 1 && grid[i][col] == size - 1)
			return (count + 1);
		i++;
	}
	return (count);
}

int	count_visible_buildings_down(int col)
{
	int	cur_max;
	int	count;
	int	i;

	cur_max = 0;
	count = 0;
	i = size - 1;
	while (i >= 0)
	{
		if (grid[i][col] > cur_max)
		{
			cur_max = grid[i][col];
			count++;
		}
		if (grid[i][col] == size)
			return (count);
		if (i > 0 && grid[i][col] == size - 1)
			return (count + 1);
		i--;
	}
	return (count);
}

int	count_visible_buildings_left(int row)
{
	int	cur_max;
	int	count;
	int	i;

	cur_max = 0;
	count = 0;
	i = 0;
	while (i < size)
	{
		if (grid[row][i] > cur_max)
		{
			cur_max = grid[row][i];
			count++;
		}
		if (grid[row][i] == size)
			return (count);
		if (i < size - 1 && grid[row][i] == size - 1)
			return (count + 1);
		i++;
	}
	return (count);
}

int	count_visible_buildings_right(int row)
{
	int	cur_max;
	int	count;
	int	i;

	cur_max = 0;
	count = 0;
	i = size - 1;
	while (i >= 0)
	{
		if (grid[row][i] > cur_max)
		{
			cur_max = grid[row][i];
			count++;
		}
		if (grid[row][i] == size)
			return (count);
		if (i > 0 && grid[row][i] == size - 1)
			return (count + 1);
		i--;
	}
	return (count);
}

// 数字を配置できるか判定
int	is_valid_placement(int row, int col, int num)
{
	if (seen[row] & (1 << (num - 1)) || seen[size + col] & (1 << (num - 1)))
		return (0);
	grid[row][col] = num;
	if (col == size - 1)
	{
		if (count_visible_buildings_left(row) != clues[2 * size + row]
			|| count_visible_buildings_right(row) != clues[3 * size + row])
		{
			grid[row][col] = 0;
			return (0);
		}
	}
	if (row == size - 1)
	{
		if (count_visible_buildings_up(col) != clues[col]
			|| count_visible_buildings_down(col) != clues[size + col])
		{
			grid[row][col] = 0;
			return (0);
		}
	}
	return (1);
}

// 再帰的にバックトラッキングで探索
int	solve(int row, int col)
{
	int	next_row;
	int	next_col;
	int	num;

	if (row == size)
	{
		return (1); // すべて埋めたらヒントを確認
	}
	if (col == size - 1)
	{
		next_row = row + 1;
		next_col = 0;
	}
	else
	{
		next_row = row;
		next_col = col + 1;
	}
	num = 1;
	while (num <= size)
	{
		if (is_valid_placement(row, col, num))
		{
			grid[row][col] = num;
			seen[row] |= (1 << (num - 1));
			seen[size + col] |= (1 << (num - 1));
			if (solve(next_row, next_col))
				return (1);
			grid[row][col] = 0;
			seen[row] ^= (1 << (num - 1));
			seen[size + col] ^= (1 << (num - 1));
		}
		num++;
	}
	return (0);
}

// 盤面を表示
void	print_grid(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			printf("%d ", grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

// メイン関数
int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	//エラーハンドリングはこの辺に
	if (argc != 2)
	{
		printf("使用方法: %s \"ヒント\"\n", argv[0]);
		return (1);
	}
	input_to_clues(argv[1]);
	if (!clues)
	{
		printf("無効な入力形式\n");
		return (1);
	}
	grid = (int **)malloc(size * sizeof(int *));
	if (!grid)
	{
		printf("メモリ確保に失敗しました");
		free(clues);
		return (1);
	}
	i = 0;
	j = 0;
	while (i < size)
	{
		grid[i] = (int *)malloc(sizeof(int) * size);
		if (!grid[i])
		{
			printf("メモリ確保に失敗しました");
			while (i--)
				free(grid[i]);
			free(grid);
			free(clues);
			return (1);
		}
		j = 0;
		while (j < size)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	init_seen();
	if (solve(0, 0))
	{
		printf("解:\n");
		print_grid();
	}
	else
	{
		printf("解が見つかりませんでした。\n");
	}
	i = 0;
	while (i < size)
		free(grid[i++]);
	free(grid);
	free(clues);
	return (0);
}
