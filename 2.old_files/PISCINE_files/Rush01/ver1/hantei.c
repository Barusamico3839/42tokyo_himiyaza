#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 4

int count_visible(int *line) {
	int max = 0;
	int count = 0;
	for (int i = 0; i < SIZE; i++) {
		if (line[i] > max) {
			max = line[i];
			count++;
		}
	}
	return count;
}

int check_board(int board[SIZE][SIZE], int clues[16]) {
	int line[SIZE];
	int i, j;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++)
			line[j] = board[j][i];
		if (count_visible(line) != clues[i])
			return 0;

		for (j = 0; j < SIZE; j++)
			line[j] = board[SIZE - 1 - j][i];
		if (count_visible(line) != clues[i + 4])
			return 0;
	}

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++)
			line[j] = board[i][j];
		if (count_visible(line) != clues[i + 8])
			return 0;

		for (j = 0; j < SIZE; j++)
			line[j] = board[i][SIZE - 1 - j];
		if (count_visible(line) != clues[i + 12])
			return 0;
	}
	return 1;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("使い方: ./rush-01 \"clues\"\n");
		return 1;
	}

	int clues[16];
	char *token = strtok(argv[1], " ");
	for (int i = 0; i < 16; i++) {
		if (!token) {
			printf("ヒントが16個ありません\n");
			return 1;
		}
		clues[i] = atoi(token);
		token = strtok(NULL, " ");
	}

	int board[SIZE][SIZE];

	// 標準入力から盤面を読み取る
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (scanf("%d", &board[i][j]) != 1) {
				printf("盤面の入力が不正です\n");
				return 1;
			}
		}
	}

	if (check_board(board, clues))
		printf("✅ 正解です！\n");
	else
		printf("❌ 不正解です。\n");

	return 0;
}
