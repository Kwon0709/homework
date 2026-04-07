#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("홀수 N 입력: ");
    scanf("%d", &N);

    // 홀수 체크
    if (N % 2 == 0) {
        printf("홀수만 가능합니다.\n");
        return 0;
    }

    // 2차원 배열 동적 할당
    int** arr = (int**)malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++) {
        arr[i] = (int*)malloc(sizeof(int) * N);
    }

    // 배열 초기화
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            arr[i][j] = 0;

    // 마방진 생성 
    int num = 1;
    int row = 0;
    int col = N / 2;

    while (num <= N * N) {
        arr[row][col] = num;

        int next_row = (row - 1 + N) % N;
        int next_col = (col + 1) % N;

        if (arr[next_row][next_col] != 0) {
            row = (row + 1) % N;
        } else {
            row = next_row;
            col = next_col;
        }

        num++;
    }

    // 배열 출력
    printf("\n[마방진]\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n[합 검증]\n");

    // 가로 합
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            sum += arr[i][j];
        }
        printf("가로 %d 합: %d\n", i + 1, sum);
    }

    // 세로 합
    for (int j = 0; j < N; j++) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += arr[i][j];
        }
        printf("세로 %d 합: %d\n", j + 1, sum);
    }

    // 대각선 합
    int diag1 = 0, diag2 = 0;
    for (int i = 0; i < N; i++) {
        diag1 += arr[i][i];
        diag2 += arr[i][N - 1 - i];
    }

    printf("대각선 1 합: %d\n", diag1);
    printf("대각선 2 합: %d\n", diag2);

    // 메모리 해제
    for (int i = 0; i < N; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
