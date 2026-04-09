#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct {
	char name[100];
	int studentNum;
	int score;
}students;

int main() {
	int N;

	printf("숫자 입력(범위 1~100): ");
	scanf("%d", &N);

	if (N > 100 || N <= 0) {
		printf("범위 안으로 입력하세요.\n");
		return 1;
	}


	students* arr = (students*)malloc(sizeof(students) * N);

	if (arr == NULL) {
		printf("메모리 할당 실패\n");
		return 1;
	}

	srand((unsigned int)time(NULL));


	FILE* fp;



	fp = fopen("C:\\Users\\ppiqq\\Desktop\\Name_list.txt", "r");
	if (fp == NULL) {

		printf("Fail to open\n");

		return 0;
	}
	
	int aver = 0;

	for (int i = 0; i < N;i++) {

		if (fgets(arr[i].name, sizeof(arr[i].name), fp) == NULL) {
		printf("이름 개수 부족\n");
		free(arr);
		fclose(fp);
		return 1;
		}
		arr[i].name[strcspn(arr[i].name, "\r\n")] = '\0';

		arr[i].studentNum = i + 1;
		arr[i].score = (rand() % 100) + 1;
		aver += arr[i].score;
	}

	int best = 0, worst = 0;
for (int i = 1; i < N; i++) {
    if (arr[i].score > arr[best].score) best = i;
    if (arr[i].score < arr[worst].score) worst = i;
}

	printf("--------------------------------------------------------\n");

	printf("최고점의 학생 정보:(이름:%s,학번:%d,성적:%d)\n", arr[best].name, arr[best].studentNum, arr[best].score);
	printf("최저점의 학생 정보:(이름:%s,학번:%d,성적:%d)\n", arr[worst].name, arr[worst].studentNum, arr[worst].score);

	printf("평균 점수:%.1f\n", (double)aver/N);

	fclose(fp);

	free(arr);

	return 0;
}
