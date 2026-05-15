#include<stdio.h>
#include<stdlib.h>

//연결리스트를 만들기 위해서는 종이와 펜이 필요?

typedef struct pointType {
	int data;
	struct pointType* next; //정의 안에 자신을 참조(자기참조구조체)
}PointType;

typedef struct linkedList {
	struct pointType* head;
	int size;
}LinkedList; //종이 역할을 수행


extern LinkedList* createLinkedList();
extern int destroyLinkedList(LinkedList* li);
extern int isEmptyLinkedList(LinkedList* li);
extern int sizeLinkedList(LinkedList* li);
extern LinkedList* insertFirstLinkedList(LinkedList* li,PointType item);
extern LinkedList* insertLastLinkedList(LinkedList* li, PointType item);
extern LinkedList* insertItemLinkedList(LinkedList*li, PointType* pre,PointType item);	
extern LinkedList* insertAtLinkedList(LinkedList* li, int at, PointType item);
extern LinkedList* deleteAtLinkedList(LinkedList* li, int at);
extern PointType deleteFirstLinkedList(LinkedList* li);
extern PointType deleteLastLinkedList(LinkedList* li);
extern PointType deleteItemLinkedList(LinkedList* li, int pos); 
extern PointType getItemLinkedList(LinkedList* li, int pos); 
extern LinkedList* replaceItemLinkedList(LinkedList* li, int pos, PointType item); 
extern PointType nextItemLinkedList(LinkedList* li, PointType* pre);
extern void printLinkedList(LinkedList* li);
