#include<stdio.h>
#include<stdlib.h>

typedef struct pointType {
	int data;
	struct pointType* prev;
	struct pointType* next;
}PointType;

typedef struct dcLinkedList {
	PointType head;
	int size;
}DcLinkedList;

extern DcLinkedList* createLinkedList();
extern void destroyLinkedList(DcLinkedList* li);
extern int isEmptyLinkedList(DcLinkedList* li);
extern int sizeLinkedList(DcLinkedList* li);
extern DcLinkedList* insertFirstLinkedList(DcLinkedList* li, PointType item);
extern DcLinkedList* insertLastLinkedList(DcLinkedList* li, PointType item);
extern DcLinkedList* insertItemLinkedList(DcLinkedList* li, PointType* pre, PointType item);
extern DcLinkedList* insertAtLinkedList(DcLinkedList* li, int at, PointType item);
extern DcLinkedList* deleteAtLinkedList(DcLinkedList* li, int at); 
extern PointType deleteFirstLinkedList(DcLinkedList* li);
extern PointType deleteLastLinkedList(DcLinkedList* li);
extern PointType deleteItemLinkedList(DcLinkedList* li, int pos); // 구현필요
extern PointType getItemLinkedList(DcLinkedList* li, int pos);
extern DcLinkedList* replaceItemLinkedList(DcLinkedList* li, int pos, PointType item);
extern PointType nextItemLinkedList(DcLinkedList* li, PointType* pre);
extern void printLinkedList(DcLinkedList* li);
