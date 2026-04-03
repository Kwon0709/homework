#include <stdio.h>
#include<stdlib.h>
#define Size 7//Size는 홀수

int main() {
    int Array[Size][Size] = { 0 };

    int row = 0;
    int col = Size/ 2 ; //열의 중앙 위치

    for (int num = 1; num <= Size * Size; num++) {
        Array[row][col] = num;

        int next_row = (row - 1 + Size) % Size;
        int next_col = (col + 1) % Size;

        if (Array[next_row][next_col] != 0) {
            next_row = (row + 1) % Size;
            next_col = col;
        }

        row = next_row;
        col = next_col;
    }

    printf("\n[ %d x %d 마방진 ]\n", Size, Size);
    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            printf("%4d", Array[i][j]);
        }
        printf("\n");
    }

    int magic = Size * (Size * Size + 1) / 2;
    printf("\n기준 합: %d\n", magic);
    printf("\n── 검증 ──\n");

    for (int i = 0; i < Size; i++) {
        int sum = 0;
        for (int j = 0; j < Size; j++) sum += Array[i][j];
        printf("가로 %d행: %d\n", i + 1, sum);
    }

    printf("--------------------\n");

    for (int j = 0; j < Size; j++) {
        int sum = 0;
        for (int i = 0; i < Size; i++) sum += Array[i][j];
        printf("세로 %d열: %d\n", j + 1, sum);
    }

    printf("--------------------\n");

    int diag1 = 0, diag2 = 0;
    for (int i = 0; i < Size; i++) {
        diag1 += Array[i][i];
        diag2 += Array[i][Size - 1 - i];
    }
    printf("대각선 (왼->오): %d\n", diag1);
    printf("대각선 (오->왼): %d\n", diag2);

    return 0;
}
