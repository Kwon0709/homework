#include<stdio.h>
#include<stdlib.h>

typedef char stackElement;

typedef struct node {
    stackElement data;
    struct node* next;
}Node;

typedef struct linkedStack {
    Node* head;
    int size;
}LinkedStack;

extern LinkedStack* createLinkedStack();
extern void destroyLinkedStack(LinkedStack* s); 
extern void initLinkedStack(LinkedStack* s);
extern int emptyLinkedStack(LinkedStack* s);
extern int fullLinkedStack(LinkedStack* s);
extern char pushLinkedStack(LinkedStack* s, stackElement item);
extern int popLinkedStack(LinkedStack* s);
extern int peekStack(LinkedStack* s);
extern void printLinkedStack(LinkedStack* s);