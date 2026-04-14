#include<stdio.h>
#include<stdlib.h>

#include"myArrayList.h"

int main() {
	int n = 0;
	int choice,pos,item;

	printf("배열의 크기를 입력해주세요: ");
	scanf_s("%d", &n);

	arrayList* myArrayList;
	myArrayList = createArrayList(n);

	if (sizeArrayList(myArrayList) == 0) {
		printf("create ok\n");
	}

	for (int i = 0;i < n;i++) {
		insertItemArrayList(myArrayList, i, rand() % 100);
	}

	printf("배열값:");
	printArrayList(myArrayList);

	printf("\n-------------------------------");

	printf("\n1.배열추가\n");
	printf("2.종료\n");

	while (1) {
		printf("입력(1 OR 2): ");
		scanf_s("%d", &choice);

		if (choice == 1) {
			printf("위치,값 입력(위치는 0부터 시작):");
			scanf_s("%d %d", &pos, &item);
			if (insertItemArrayList(myArrayList, pos, item))
			{printf("삽입 성공 (현재 capacity: %d)\n", myArrayList->capacity);
			printf("현재 배열: ");
			printArrayList(myArrayList);
			printf("\n");}
			else
				printf("삽입 실패\n");
		}
		else if (choice == 2) {
			break;
		}
		else {
			printf("1또는 2만 입력해주세요\n");
		}


	}

	printf("------------------------\n");
	printf("최종 배열: ");
	printArrayList(myArrayList);
	printf("\n(최종 size: %d, capacity: %d)\n", myArrayList->size, myArrayList->capacity);


	destroyArrayList(myArrayList);

	return 0;
}
