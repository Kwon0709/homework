#include<stdio.h>
#include<stdlib.h>

typedef int stackElement;

typedef struct node {
    stackElement data;
    struct node* next;
}Node;

typedef struct linkedStack {
    Node* head;
    int size;
}LinkedStack;

extern LinkedStack* createLinkedStack();
extern void destroyLinkedStack(LinkedStack* s); //구현필요
extern void initLinkedStack(LinkedStack* s);
extern int emptyLinkedStack(LinkedStack* s);
extern int fullLinkedStack(LinkedStack* s);
extern int pushLinkedStack(LinkedStack* s, stackElement item);
extern int popLinkedStack(LinkedStack* s);
extern int peekStack(LinkedStack* s);
extern void printLinkedStack(LinkedStack* s);