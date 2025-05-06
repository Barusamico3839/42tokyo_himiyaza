#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SIZE 4

// ヘルパー関数：ビルが見える数をカウント
int count_visible(int *row, int size) {
    int max = 0;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (row[i] > max) {
            max = row[i];
            count++;
        }
    }
    return count;
}

// シャッフル（Fisher-Yates）
void shuffle(int *arr, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// ランダムな有効な解盤面を生成（各行に 1〜4 をランダムに並べる）
void generate_solution(int board[SIZE][SIZE]) {
    int row[SIZE];
    for (int i = 0; i < SIZE; i++)
        row[i] = i + 1;

    for (int i = 0; i < SIZE; i++) {
        shuffle(row, SIZE);
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = row[j];
        }
    }
}

// ヒントを計算
void calculate_clues(int board[SIZE][SIZE], int top[SIZE], int bottom[SIZE], int left[SIZE], int right[SIZE]) {
    int temp[SIZE];

    for (int col = 0; col < SIZE; col++) {
        for (int row = 0; row < SIZE; row++)
            temp[row] = board[row][col];
        top[col] = count_visible(temp, SIZE);

        for (int row = 0; row < SIZE; row++)
            temp[row] = board[SIZE - 1 - row][col];
        bottom[col] = count_visible(temp, SIZE);
    }

    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++)
            temp[col] = board[row][col];
        left[row] = count_visible(temp, SIZE);

        for (int col = 0; col < SIZE; col++)
            temp[col] = board[row][SIZE - 1 - col];
        right[row] = count_visible(temp, SIZE);
    }
}

void print_clues(int top[], int bottom[], int left[], int right[]) {
    // printf("Top:    ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", top[i]);

	// printf("Bottom: ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", bottom[i]);

    // printf("Left:   ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", left[i]);

    // printf("Right:  ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", right[i]);

}

int main()
{
    int board[SIZE][SIZE];
    int top[SIZE], bottom[SIZE], left[SIZE], right[SIZE];

    srand(time(NULL));  // 乱数の初期化

    generate_solution(board);
    calculate_clues(board, top, bottom, left, right);
    print_clues(top, bottom, left, right);

    return 0;
}
