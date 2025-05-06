#include <stdio.h>
#include <stdlib.h>

#define N 4

int count_visible(int line[N]) {
	int max = 0;
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (line[i] > max) {
			max = line[i];
			count++;
		}
	}
	return count;
}

void extract_col(int board[N][N], int col, int line[N], int reverse) {
	for (int i = 0; i < N; i++)
		line[i] = reverse ? board[N - 1 - i][col] : board[i][col];
}

void extract_row(int board[N][N], int row, int line[N], int reverse) {
	for (int i = 0; i < N; i++)
		line[i] = reverse ? board[row][N - 1 - i] : board[row][i];
}

int main(int argc, char **argv) {
	if (argc != 1 + N * N) {
		printf("Usage: ./a.out 16_numbers\n");
		return 1;
	}

	int board[N][N];
	int line[N];
	int k = 1;

	// 入力を2次元配列に変換
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = atoi(argv[k++]);
		}
	}

	// 上から
	for (int col = 0; col < N; col++) {
		extract_col(board, col, line, 0);
		printf("%d ", count_visible(line));
	}

	// 下から
	for (int col = 0; col < N; col++) {
		extract_col(board, col, line, 1);
		printf("%d ", count_visible(line));
	}

	// 左から
	for (int row = 0; row < N; row++) {
		extract_row(board, row, line, 0);
		printf("%d ", count_visible(line));
	}

	// 右から
	for (int row = 0; row < N; row++) {
		extract_row(board, row, line, 1);
		printf("%d ", count_visible(line));
	}

	printf("\n");
	return 0;
}
