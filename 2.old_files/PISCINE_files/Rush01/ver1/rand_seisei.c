#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

/*
** 1行(4マス)について、左から見た時の「見えるビルの数」を返す
*/
int	count_visible(int *line)
{
	int	count;
	int	max;
	int	i;

	count = 0;
	max = 0;
	i = 0;
	while (i < SIZE)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count);
}

/*
** 1桁の数字をwriteで出力する小関数 (Norm対策)
*/
static void	put_digit(int n)
{
	char c;

	c = '0' + n;
	write(1, &c, 1);
}

/*
** ランダムに生成した 4x4 の配置 (grid) に対応するヒントを表示
**
** 出力形式：
** hint:
** (上から見た各列4つ) (下から見た各列4つ)
** (左から見た各行4つ) (右から見た各行4つ)
**
** answer:
** (gridの中身)
*/
void	print_hints_and_answer(int grid[SIZE][SIZE])
{
	int tmp[SIZE];
	int i, j;

	/* ヒント出力 */
	write(1, "hint:\n", 6);

	/* 上から見た各列 */
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
			tmp[j] = grid[j][i]; // grid[row][col] → row=j, col=i
		put_digit(count_visible(tmp));
		write(1, " ", 1);
	}

	/* 下から見た各列 */
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
			tmp[j] = grid[SIZE - 1 - j][i];
		put_digit(count_visible(tmp));
		write(1, " ", 1);
	}

	/* 左から見た各行 */
	for (i = 0; i < SIZE; i++)
	{
		put_digit(count_visible(grid[i]));
		write(1, " ", 1);
	}

	/* 右から見た各行 */
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
			tmp[j] = grid[i][SIZE - 1 - j];
		put_digit(count_visible(tmp));
		write(1, " ", 1);
	}

	write(1, "\n\nanswer:\n", 10);

	/* 解答(4x4)出力 */
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			put_digit(grid[i][j]);
			write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

/*
** 1,2,3,4 の全順列24パターンを列挙 (静的配列)
*/
static int g_perms[24][4] = {
	{1,2,3,4},{1,2,4,3},{1,3,2,4},{1,3,4,2},
	{1,4,2,3},{1,4,3,2},{2,1,3,4},{2,1,4,3},
	{2,3,1,4},{2,3,4,1},{2,4,1,3},{2,4,3,1},
	{3,1,2,4},{3,1,4,2},{3,2,1,4},{3,2,4,1},
	{3,4,1,2},{3,4,2,1},{4,1,2,3},{4,1,3,2},
	{4,2,1,3},{4,2,3,1},{4,3,1,2},{4,3,2,1}
};

/*
** g_perms をランダムにシャッフル (Fisher-Yates 法)
*/
void shuffle_perms(void)
{
	for (int i = 0; i < 24; i++)
	{
		int r = rand() % 24;
		for (int k = 0; k < 4; k++)
		{
			int tmp = g_perms[i][k];
			g_perms[i][k] = g_perms[r][k];
			g_perms[r][k] = tmp;
		}
	}
}

/*
** 既に決定した行(0..r-1)と、新しく行として選びたい perm[] (4要素) を比べて
** 列で重複がないか確認する。重複があれば0, なければ1を返す。
*/
int	col_check(int grid[SIZE][SIZE], int r, int perm[4])
{
	for (int c = 0; c < SIZE; c++)
	{
		int val = perm[c];
		/* 上の行をチェック */
		for (int rr = 0; rr < r; rr++)
		{
			if (grid[rr][c] == val)
				return (0); // 列 c で重複
		}
	}
	return (1); // 重複なし
}

/*
** ランダムに 4行を決定 (行重複なし & 列重複なし)
** 1) 24個の順列をシャッフル
** 2) 先頭から順に「行として使用可能か」チェックし、4行集まれば完成
** 3) 集まらなければ再度シャッフルしてやり直し
*/
void	generate_4x4(int grid[SIZE][SIZE])
{
	while (1)
	{
		int used_rows = 0; // 何行決まったか
		int idx = 0;
		/* いったん全部クリア */
		for (int r = 0; r < SIZE; r++)
			for (int c = 0; c < SIZE; c++)
				grid[r][c] = 0;

		shuffle_perms();
		/* 24個の順列を前から見て、使えるものを順に行として決定 */
		for (int p = 0; p < 24 && used_rows < SIZE; p++)
		{
			/* 行(used_rows)に g_perms[p]を当てはめられる？ */
			if (col_check(grid, used_rows, g_perms[p]))
			{
				/* OKならコピー */
				for (int c = 0; c < SIZE; c++)
					grid[used_rows][c] = g_perms[p][c];
				used_rows++;
			}
		}
		/* 全4行決まったらbreak */
		if (used_rows == SIZE)
			break;
		/* ダメなら while(1) で再試行 */
	}
}

int	main(void)
{
	int grid[SIZE][SIZE];

	srand(time(NULL));

	/* 各行・各列に重複がない4x4を生成 */
	generate_4x4(grid);

	/* ヒントとanswerを出力 */
	print_hints_and_answer(grid);

	return (0);
}
