#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20

int main() {
	int Array[N];

	srand(time(NULL)); //매번 다른 랜덤값 호출

	printf("=======================================\n");
	for (int i = 0; i < N;i++) {
		Array[i] = rand() % (N + 1);

		printf("{%d}\t", Array[i]);
		if ((i + 1) % 5 == 0) printf("\n");
	}

	printf("\n");

	printf("=======================================\n");

	for (int j = N - 1; j >= 0; j--) {
		printf("{%d}\t", Array[j]);
		if ((N - j) % 5 == 0) printf("\n");
	}

	printf("\n");

	int Sum = 0;
	int Max = Array[0];
	int Min = Array[0];

	for (int i = 0; i < N; i++) {
		Sum += Array[i];

		if (Max < Array[i]) { Max = Array[i]; }
		if (Min > Array[i]) { Min = Array[i]; }
	}

	printf("-------------------------------------\n");

	printf("Sum:%d || MAX:%d || MIN:%d\n", Sum, Max, Min);

	printf("-------------------------------------");

	return 0;
}
