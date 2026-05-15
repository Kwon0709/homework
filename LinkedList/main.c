#include<stdio.h>
#include<stdlib.h>

#include "LinkedList.h"

int main() {
	struct linkedList* myList1;
	myList1 = createLinkedList();

	int choi, date, at, size;
	int a = 0;

	while (a == 0) {
		printf("1. 맨 앞에 추가: 정수를 입력받아 리스트의 가장 앞에 삽입\n");
		printf("2. 맨 뒤에 추가 : 정수를 입력받아 리스트의 가장 뒤에 삽입\n");
		printf("3. 특정 위치에 추가: 위치(index)와 정수를 입력받아 해당 위치에 삽입\n");
		printf("4. 특정 위치 삭제: 위치(index)를 입력받아 해당 노드를 삭제하고 값 출력\n");
		printf("5. 전체 목록 출력: 현재 리스트에 저장된 모든 정수를 순서대로 출력\n");
		printf("6. 리스트 크기 확인: 현재 저장된 노드의 총 개수를 출력\n");
		printf("0. 종료: 모든 메모리를 해제(destroy)하고 프로그램을 종료\n");
		printf("입력:");
		scanf_s("%d", &choi);

		switch (choi) {
		case 1:
			printf("추가할 정수 입력:");
			scanf_s("%d", &date);
			insertFirstLinkedList(myList1, (PointType) { date });
			break;
		case 2:
			printf("추가할 정수 입력:");
			scanf_s("%d", &date);
			insertLastLinkedList(myList1, (PointType) { date });
			break;
		case 3:
			printf("추가할 위치 입력:");
			scanf_s("%d", &at);
			printf("추가할 정수 입력:");
			scanf_s("%d", &date);
			insertAtLinkedList(myList1, at, (PointType) { date });
			break;
		case 4:
			printf("삭제할 위치 입력:");
			scanf_s("%d", &at);
			PointType delete = getItemLinkedList(myList1, at);
			deleteAtLinkedList(myList1, at);
			printf("삭제 된 값:%d\n", delete.data);
			break;
		case 5:
			printLinkedList(myList1);
			break;
		case 6:
			size = sizeLinkedList(myList1);
			printf("size:%d\n", size);
			break;
		case 0:
			destroyLinkedList(myList1);
			a = 1;
			break;
		default:
			printf("메뉴에 있는 번호를 입력해주세요.\n");
			break;
		}
	}
	return 0;

}
