#include"DcLinkedList.h"

DcLinkedList* createLinkedList() {
	DcLinkedList* temp;
	temp = (DcLinkedList*)malloc(sizeof(DcLinkedList));
	temp->head.prev = &(temp->head);
	temp->head.next = &(temp->head);
	temp->size = 0;

	return temp;
}

void destroyLinkedList(DcLinkedList* li) {
	while (li->size != 0) {
		deleteFirstLinkedList(li);
	}
	free(li);
} //deleteFirstLinkedList 구현후 마무리하기

int isEmptyLinkedList(DcLinkedList* li) {
	return li->head.next == &(li->head);
}

int sizeLinkedList(DcLinkedList* li) {
	return li->size;
}

DcLinkedList* insertFirstLinkedList(DcLinkedList* li, PointType item) {
	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;

	nPtr->prev = &(li->head);
	nPtr->next = li->head.next;
	li->head.next = nPtr;
	nPtr->next->prev = nPtr;

	li->size++;

	return li;
}

DcLinkedList* insertLastLinkedList(DcLinkedList* li, PointType item) {
	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;

	nPtr->prev = li->head.prev;
	nPtr->next = &(li->head);
	nPtr->prev->next = nPtr;
	nPtr->next->prev = nPtr;

	li->size++;

	return li;
}

DcLinkedList* insertItemLinkedList(DcLinkedList* li, PointType* pre, PointType item) {
	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;
	nPtr->prev = pre;
	nPtr->next = pre->next;
	nPtr->prev->next = nPtr;
	nPtr->next->prev = nPtr;

	li->size++;

	return li;
}

DcLinkedList* insertAtLinkedList(DcLinkedList* li, int at, PointType item) {
	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;
	 if (at >= 0 && at <= li->size) {
		PointType* fPtr=&(li->head);
		for (int i = 0;i < at ;i++) {
			fPtr = fPtr->next;
		}
		nPtr->prev = fPtr;
		nPtr->next = fPtr->next;
		nPtr->prev->next = nPtr;
		nPtr->next->prev = nPtr;
		li->size++;
	 }
	 else {
		 printf("올바른 위치가 아닙니다.\n");
		 free(nPtr);
		 return li;
	 }

	return li;
}

PointType deleteFirstLinkedList(DcLinkedList* li) {
	if (li->head.next == &(li->head)) return (PointType) { 0 };

	PointType* temp = li->head.next;
	PointType result = *temp;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;

	li->size--;
	free(temp);

	return result;
}

PointType deleteLastLinkedList(DcLinkedList* li) {
	if (li->head.prev == &(li->head)) return (PointType) { 0 };

	PointType* temp = li->head.prev;
	PointType result = *temp;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	li->size--;

	free(temp);

	return result;
}

DcLinkedList* deleteAtLinkedList(DcLinkedList* li, int at) {
	if (at >= 0 && at < li->size) {
		PointType* fPtr = &(li->head);
		for (int i = 0;i <= at;i++) {
			fPtr = fPtr->next;
		}
		fPtr->prev->next = fPtr->next;
		fPtr->next->prev = fPtr->prev;
		free(fPtr);
		li->size--;
	}
	else {
		printf("잘못된 위치 입니다.\n");
	}

	return li;
}

PointType deleteItemLinkedList(DcLinkedList* li, int pos) {
	if (li->head.next == &(li->head)) return (PointType) { 0 };

	PointType* fPtr = li->head.next;

	while (fPtr != &(li->head)) {
		if (fPtr->data == pos) {
			PointType result = *fPtr; 

			fPtr->prev->next = fPtr->next;
			fPtr->next->prev = fPtr->prev;
			free(fPtr);
			li->size--;

			return result;
		}
		fPtr = fPtr->next;
	}

	printf("해당 값을 찾을 수 없습니다.\n");
	return (PointType) { 0 };
}

PointType getItemLinkedList(DcLinkedList* li, int pos) {
	PointType* ptr;

	if (pos < 0 || pos >= li->size) {
		return (PointType) { 0 };
	}

	ptr = li->head.next;

	for (int i = 0;i < pos;i++) {
		ptr = ptr->next;
	}

	return *ptr;
}

DcLinkedList* replaceItemLinkedList(DcLinkedList* li, int pos, PointType item) {
	if (pos < 0 || pos >= li->size) return li;

	PointType* ptr = li->head.next;
	for (int i = 0; i < pos; i++) {
		ptr = ptr->next;
	}

	ptr->data = item.data;

	return li;
}

PointType nextItemLinkedList(DcLinkedList* li, PointType* pre) {
	PointType* ptr = li->head.next;
	if (pre == &(li->head)) {
		if (li->head.next == &(li->head)) return (PointType) { 0 };
		PointType temp = *ptr;
		return temp;	
	}

	PointType* nPtr = pre->next;
	if (nPtr == &(li->head)) {
		nPtr = li->head.next;  
	}

	PointType temp = *nPtr;
	return temp;
}

void printLinkedList(DcLinkedList* li) {
	printf("Print DLinkedList:\n");

	if (li->size == 0) {
		return;
	}

	PointType* start = li->head.next;

	for (int i = 0; i < li->size; i++) {
		printf("[%d] x: %d, next: %x\n",i, start->data,start->next);

		start = start->next;
	}
}
