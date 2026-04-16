#include<stdio.h>
#include<stdlib.h>

#include"myArrayList.h"

void printNum() {
	printf("1.삽입(insert)\n");
	printf("2.삭제(delete)\n");
	printf("3.변경(replace)\n");
	printf("4.출력(print)\n");
	printf("5.삭제(clear)\n");
	printf("0.종료(end)\n");
}


int main() {
	int n = 0;
	int choice, pos, item;

	printf("배열의 크기를 입력해주세요: ");
	scanf_s("%d", &n);

	arrayList* myArrayList;
	myArrayList = createArrayList(n);

	if (sizeArrayList(myArrayList) == 0) {
		printf("create ok\n");
	}

	printNum();

	while (1) {
		printf("번호 입력: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("삽입할 위치, 값 입력(위치는 0부터 시작):");
			scanf_s("%d %d", &pos, &item);
			if (insertItemArrayList(myArrayList, pos, item))
				printf("삽입 성공\n");
			else
				printf("삽입 실패\n");
			break;
		case 2:
			printf("삭제할 위치 입력: ");
			scanf_s("%d", &pos);
			item = deleteItemArrayList(myArrayList, pos);
			if (item == 0) printf("삭제 실패 (잘못된 위치)\n");
			else printf("삭제된 값: %d\n", item);
			break;
		case 3:
			printf("변경할 위치, 값 입력:");
			scanf_s("%d %d", &pos, &item);
			if (replaceItemArrayList(myArrayList, pos, item))
				printf("변경 성공\n");
			else
				printf("변경 실패\n");
			break;
		case 4:
			printArrayList(myArrayList);
			printf("\n");
			break;
		case 5:
			initArrayList(myArrayList);
			break;
		case 0:
			printf("------------------------\n");
			printf("최종배열: ");
			printArrayList(myArrayList);
			printf("\n(최종 size: %d, capacity: %d)\n", myArrayList->size, myArrayList->capacity);
			destroyArrayList(myArrayList);
			return 0;
		default:
			printf("보기에 있는 번호만 입력해주세요\n");
		}

	}
}
