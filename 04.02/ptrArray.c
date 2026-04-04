#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	int N = 0;

	printf("숫자 입력: ");
	scanf_s("%d", &N);

	 if (N <= 0) {
        printf("양수만 입력하세요.\n");
        return 1;
    }


	int* arr = (int*)malloc(sizeof(int)*N);

	if (arr == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }
	
	srand(time(NULL));

	int* ptr = arr;

	printf("정방향 출력: ");

	for (int i = 0;i < N;i++)
	{
		*ptr = rand() % (N + 1);
		ptr++;
	}

	ptr=arr;

	for (int i = 0;i < N;i++) {
		printf("%d ", *ptr);
		ptr++;
	}

	printf("\n");

	int* reptr= arr+N-1;
	printf("역방향 출력: ");
	for (int i = 0;i < N;i++) {
		printf("%d ", *reptr);
		reptr--;
	}

	printf("\n");

	ptr = arr;
	int max = *ptr;
	int min = *ptr;

	int sum = 0;

	for (int i = 0; i < N; i++) {
		sum += *ptr;

		if (*ptr > max)max = *ptr;
		if (*ptr < min)min = *ptr;
		ptr++;
	}

	printf("\n");

	printf("합:%d\n", sum);
	printf("최대값:%d\n", max);
	printf("최소값:%d\n", min);

	free(arr);

	return 0;
}
