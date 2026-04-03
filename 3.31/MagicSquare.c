#include <stdio.h>
#include<stdlib.h>
#define N 7//N 홀수

int main() {
    int Array[N][N] = { 0 };

    int row = 0;
    int col = N/ 2 ; //열의 중앙 위치

    for (int num = 1; num <= N * N; num++) {
        Array[row][col] = num;

        int next_row = (row - 1 + N) % N;
        int next_col = (col + 1) % N;

        if (Array[next_row][next_col] != 0) {
            next_row = (row + 1) % N;
            next_col = col;
        }

        row = next_row;
        col = next_col;
    }

    printf("\n[ %d x %d 마방진 ]\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d", Array[i][j]);
        }
        printf("\n");
    }

    int magic = N * (N * N + 1) / 2;
    printf("\n기준 합: %d\n", magic);
    printf("\n── 검증 ──\n");

    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) sum += Array[i][j];
        printf("가로 %d행: %d\n", i + 1, sum);
    }

    printf("--------------------\n");

    for (int j = 0; j < N; j++) {
        int sum = 0;
        for (int i = 0; i < N; i++) sum += Array[i][j];
        printf("세로 %d열: %d\n", j + 1, sum);
    }

    printf("--------------------\n");

    int diag1 = 0, diag2 = 0;
    for (int i = 0; i < N; i++) {
        diag1 += Array[i][i];
        diag2 += Array[i][N - 1 - i];
    }
    printf("대각선 (왼->오): %d\n", diag1);
    printf("대각선 (오->왼): %d\n", diag2);

    return 0;
}
