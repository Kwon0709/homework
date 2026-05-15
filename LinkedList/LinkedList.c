#include"linkedList.h"

LinkedList* createLinkedList() {
	LinkedList* r;
	r = (LinkedList*)malloc(sizeof(LinkedList));

	r->head = (struct pointType*)NULL;
	r->size = (struct pointType*)NULL;


	return r;
}

int destroyLinkedList(LinkedList* li) {
	PointType* nptr, * mptr;
	for (nptr = li->head;nptr != NULL;nptr = mptr) {
		mptr = nptr->next;
		free(nptr);
	}

	free(li);

	return 1;
}

int isEmptyLinkedList(LinkedList* li) {
	return (li->size == 0);
}

int sizeLinkedList(LinkedList* li) {
	return li->size;
}

LinkedList* insertFirstLinkedList(LinkedList* li,PointType item) {
	PointType* ptr = (PointType*)malloc(sizeof(PointType));
	*ptr = item;

	ptr->next = li->head;
	li->head = ptr;

	li->size++;		

	return li;
}

LinkedList* insertLastLinkedList(LinkedList* li, PointType item) {
	PointType* ptr = li->head;
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}

	PointType* nptr = (PointType*)malloc(sizeof(PointType));
	*nptr = item;
	nptr->next = NULL;
	ptr->next = nptr;

	li->size++;

	return li;
}

LinkedList* insertItemLinkedList(LinkedList* li, PointType* pre, PointType item) {
	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;
	if (pre != NULL) {
		nPtr->next = pre->next;
		pre->next = nPtr; //연결리스트 안에 한개라도 있을경우
	}
	else {
		nPtr->next = li->head;
		li->head = nPtr; //한개라도 없을 경우
	}

	li->size++;

	return li;
}

LinkedList* insertAtLinkedList(LinkedList* li, int at, PointType item) {
	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;
	if (at >= 0 && at <= li->size) {
		if (at == 0) {
			nPtr->next = li->head;
			li->head = nPtr;
		}
		else {
			PointType* fptr = li->head;
			for (int i = 0;i < at - 1;i++) {
				fptr = fptr->next;
			}
			nPtr->next = fptr->next;
			fptr->next = nPtr;
			
		}
		li->size++;
	}
	return li;
}

LinkedList* deleteAtLinkedList(LinkedList* li, int at) {
	if (at >= 0 && at < li->size) {
		if (at == 0) {
			PointType* fptr = li->head;
			li->head = fptr->next;

			free(fptr);
		}
		else {
			PointType* nptr = li->head;
			for (int i = 0; i < at - 1;i++) {
				nptr = nptr->next;
			}
			PointType* fptr = nptr->next;
			nptr->next = fptr->next;
			free(fptr);
		}
		li->size--;
	}
	return li;
}

PointType deleteFirstLinkedList(LinkedList* li) {
	PointType* tPtr = li->head;
	li->head = tPtr->next;
	if (li->size != 0) {
		PointType temp = *tPtr;
		free(tPtr);
		li->size--;
		return temp;
	}
	else {
		return (PointType) { 0, 0 };
	}
}

PointType deleteItemLinkedList(LinkedList* li,int pos)
{
	PointType* pre = NULL;
	PointType* dPtr = li->head;

	// 리스트 탐색
	while (dPtr != NULL) {

		// 값 찾음
		if (dPtr->data == pos) {

			// 첫 노드 삭제
			if (pre == NULL) {
				li->head = dPtr->next;
			}

			// 중간/끝 삭제
			else {
				pre->next = dPtr->next;
			}

			PointType temp = *dPtr;

			free(dPtr);

			li->size--;

			return temp;
		}

		pre = dPtr;
		dPtr = dPtr->next;
	}

	// 못 찾은 경우
	return (PointType) { 0 };
}
PointType deleteLastLinkedList(LinkedList* li) {
	PointType* pre;
	PointType* iPtr;

	pre = li->head;

	if (pre == NULL) {
		return (PointType) { 0, 0};
	}
	iPtr = pre->next;

	if (iPtr == 0) {
		li->head = NULL;
		
		PointType temp;
		temp = *pre;
		free(pre);

		li->size--;
		return temp;
	}
	else {
		while (iPtr->next != NULL) {
			pre = iPtr;
			iPtr = iPtr->next;
		}

		PointType temp;
		temp = *iPtr;

		pre->next = NULL;
		free(iPtr);
		li->size--;
		return temp;
	}
}

PointType getItemLinkedList(LinkedList* li, int pos) {
	PointType* ptr;

	// 범위 검사
	if (pos < 0 || pos >= li->size) {
		return (PointType) { 0, NULL };
	}

	// head부터 시작
	ptr = li->head;

	// pos 위치까지 이동
	for (int i = 0; i < pos; i++) {
		ptr = ptr->next;
	}

	// 해당 노드 반환
	return *ptr;
}
LinkedList* replaceItemLinkedList(LinkedList* li, int pos, PointType item) {
	if (pos < 0 || pos >= li->size) return li;

	PointType* ptr = li->head;
	for (int i = 0; i < pos; i++) {
		ptr = ptr->next;
	}

	ptr->data = item.data; 

	return li;
}

PointType nextItemLinkedList(LinkedList* li, PointType* pre) {
	PointType* ptr = li->head;
	if (pre == NULL) {
		// pre가 NULL이면 첫 번째 노드 반환
		if (li->head == NULL) return (PointType) { 0 };
		PointType temp = *ptr;
		return ;
	}

	PointType* nPtr = pre->next;
	if (pre->next == NULL) {
		// 다음 노드 없음
		return (PointType) { 0 };
	}
	PointType temp = *nPtr;
	return temp;  // pre의 다음 노드 반환
}

void printLinkedList(LinkedList* li) {
	PointType* current = li->head;

	printf("LInkedList\n");

	for (int i = 0;i < li->size;i++) {
		printf("[%d] x:%d, next:%x\n",i,current->data, current->next);
		current = current->next;

	}
}
