#include<stdio.h>
#include<stdlib.h>

int main() {
	int N = 0;
	printf("홀수 입력: ");
	scanf_s("%d", &N);

	if (N % 2 == 0 || N <= 0) {
		printf("홀수만 입력하세요.\n");
		return 1;
	}

	int* arr = (int*)calloc(N*N,sizeof(int));

	int row = 0;
	int col = N / 2;

	for (int i = 1;i <= N * N;i++) {
		*(arr+row*N+col)=i;

		int next_row = (row - 1 + N) % N;
		int next_col = (col + 1) % N;

		if (*(arr+next_row*N+next_col) != 0) {
			next_row = (row + 1) % N;
			next_col = col;
		}

		row = next_row;
		col = next_col;
	}

	printf("\n[ %d x %d 마방진 ]\n", N, N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%5d", *(arr+i*N+j));
		}
		printf("\n");
	}

	int Magic_sum = N * (N * N + 1) / 2;
	printf("기준 합:%d\n",Magic_sum);
	printf("ㅡㅡ검증ㅡㅡ\n");

	for (int i = 0;i < N;i++) {
		int row_sum = 0;
		for (int j = 0;j < N;j++) row_sum += *(arr + i * N + j);
			printf("가로 %d행 합:%d\n",i+1,row_sum);
	}

	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");

	for (int j = 0;j < N;j++) {
		int col_sum = 0;
		for (int i = 0;i < N;i++) col_sum += *(arr + i * N + j);
		printf("세로 %d행 합 :%d\n", j + 1, col_sum);
	}

	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");

	int diag1 = 0, diag2 = 0;
	for (int i = 0;i < N;i++) {
		diag1 += *(arr + i * N + i); //왼->오
		diag2 += *(arr + i * N + (N-1) - i);//오->왼
	}

	printf("왼->오:%d\n", diag1);
	printf("오->왼:%d\n", diag2);

	free(arr);

	return 0;
}
