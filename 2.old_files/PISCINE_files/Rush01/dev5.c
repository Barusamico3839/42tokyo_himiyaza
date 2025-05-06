#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

typedef	struct {
    int size;
    int **grid;
    int *clues;
    int *seen;
} Puzzle;

int	ft_strlen(char *str)
{
    char *ptr;

	ptr = str;
    while (*ptr)
        ptr++;
    return (ptr - str);
}

void	ft_putstr(char *str)
{
	ft_strlen(str);
	write(1, str, ft_strlen);
	write(1, "\n", 1);
}

void	ft_putstr_error(char *str)
{
	ft_strlen(str);
	write(2, str, ft_strlen);
	write(2, "\n", 1);
}

void	init_seen(Puzzle *puzzle) {
    puzzle->seen = (int *)malloc(sizeof(int) * puzzle->size * 2);
    int i;

	i = 0;
    while (i < puzzle->size * 2)
	{
        puzzle->seen[i] = 0;
        i++;
    }
}

void	input_to_clues(Puzzle *puzzle, char *str) {
    int len;

	len = ft_strlen(str);
    if (len % 8 != 7)
	{
        ft_putstr_error("Error\n, 無効な入力形式\n");
        exit(1);
    }
    puzzle->size = (len + 1) / 8;
    puzzle->clues = (int *)malloc(sizeof(int) * (4 * puzzle->size));
    if (!puzzle->clues)
	{
        ft_putstr_error("Error\nメモリの確保に失敗しました");
        exit(1);
    }
    int i = 0;
    while (i < len)
	{
        if (i % 2 == 0)
		{
            if (str[i] < '1' || str[i] > ('0' + puzzle->size))
			{
                ft_putstr_error("Error\n無効な入力形式です。");
                free(puzzle->clues);
                exit(1);
            }
            puzzle->clues[i / 2] = str[i] - '0';
        }
		else if (str[i] != ' ')
		{
            ft_putstr_error("Error\n無効な入力形式です。");
            free(puzzle->clues);
            exit(1);
        }
        i++;
    }
}

int count_visible_buildings_up(Puzzle *puzzle, int col)
{
    int cur_max;
	int count;
	int i;

	cur_max = 0;
	count = 0;
	i = 0;
    while (i < puzzle->size)
	{
        if (puzzle->grid[i][col] > cur_max)
		{
            cur_max = puzzle->grid[i][col];
            count++;
        }
    	i++;
    }
    return (count);
}

int count_visible_buildings_down(Puzzle *puzzle, int col)
{
    int cur_max;
	int count;
	int i;

	cur_max= 0;
	count = 0;
	i = puzzle->size - 1;
    while (i >= 0)
	{
        if (puzzle->grid[i][col] > cur_max)
		{
            cur_max = puzzle->grid[i][col];
            count++;
        }
        i--;
    }
    return (count);
}

int count_visible_buildings_left(Puzzle *puzzle, int row)
{
    int cur_max;
	int count;
	int i;

	cur_max= 0;
	count = 0;
	i = 0;
    while (i < puzzle->size)
	{
        if (puzzle->grid[row][i] > cur_max)
		{
            cur_max = puzzle->grid[row][i];
            count++;
        }
        i++;
    }
    return (count);
}

int count_visible_buildings_right(Puzzle *puzzle, int row)
{
    int cur_max;
	int count;
	int i;

	cur_max = 0;
	count = 0;
	i = puzzle->size - 1;
    while (i >= 0) {
        if (puzzle->grid[row][i] > cur_max)
		{
            cur_max = puzzle->grid[row][i];
            count++;
        }
        i--;
    }
    return (count);
}

int is_valid_placement(Puzzle *puzzle, int row, int col, int num) {
    if (puzzle->seen[row] & (1 << (num - 1)) || puzzle->seen[puzzle->size + col] & (1 << (num - 1)))
        return (0);
    puzzle->grid[row][col] = num;
    if (col == puzzle->size - 1)
	{
        if (count_visible_buildings_left(puzzle, row) != puzzle->clues[2 * puzzle->size + row] ||
            count_visible_buildings_right(puzzle, row) != puzzle->clues[3 * puzzle->size + row])
		{
            puzzle->grid[row][col] = 0;
            return (0);
        }
    }
    if (row == puzzle->size - 1)
	{
        if (count_visible_buildings_up(puzzle, col) != puzzle->clues[col] ||
            count_visible_buildings_down(puzzle, col) != puzzle->clues[puzzle->size + col])
		{
            puzzle->grid[row][col] = 0;
            return (0);
        }
    }
    return (1);
}

int solve(Puzzle *puzzle, int row, int col) {
	int next_row;
	int next_col;
	int num;

    if (row == puzzle->size)
        return (1);
	if (col == puzzle -> size - 1)
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
    while (num <= puzzle->size) {
        if (is_valid_placement(puzzle, row, col, num))
		{
            puzzle->grid[row][col] = num;
            puzzle->seen[row] |= (1 << (num - 1));
            puzzle->seen[puzzle->size + col] |= (1 << (num - 1));
            if (solve(puzzle, next_row, next_col))
                return (1);
            puzzle->grid[row][col] = 0;
            puzzle->seen[row] ^= (1 << (num - 1));
            puzzle->seen[puzzle->size + col] ^= (1 << (num - 1));
        }
        num++;
    }
    return 0;
}

void print_grid(Puzzle *puzzle)
{
    int i;
	int j;

	i = 0;
    while (i < puzzle->size) {
        j = 0;
        while (j < puzzle->size) {
            printf("%d ", puzzle->grid[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("\u4f7f\u7528\u65b9\u6cd5: %s \"\u30d2\u30f3\u30c8\"\n", argv[0]);
        return 1;
    }
    Puzzle puzzle;
    input_to_clues(&puzzle, argv[1]);
    puzzle.grid = (int **)malloc(puzzle.size * sizeof(int *));
    int i = 0;
    while (i < puzzle.size) {
        puzzle.grid[i] = (int *)malloc(sizeof(int) * puzzle.size);
        int j = 0;
        while (j < puzzle.size) {
            puzzle.grid[i][j] = 0;
            j++;
        }
        i++;
    }
    init_seen(&puzzle);

    if (solve(&puzzle, 0, 0))
	{
        print_grid(&puzzle);
    }
	else
        ft_putstr_error("解が見つかりませんでした。");

    i = 0;
    while (i < puzzle.size)
        free(puzzle.grid[i++]);

    free(puzzle.grid);
    free(puzzle.clues);
    free(puzzle.seen);
    return 0;
}
