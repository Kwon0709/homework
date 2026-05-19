#include"LinkedStack.h"

LinkedStack* createLinkedStack() {
    LinkedStack* re = (LinkedStack*)malloc(sizeof(LinkedStack));
    re->head = NULL;
    re->size = 0;

    return re;
}

void destroyLinkedStack(LinkedStack* s) {
    Node* nPtr, * mPtr;
    for (nPtr = s->head;nPtr != NULL;nPtr = mPtr) {
        mPtr = nPtr->next;
        free(nPtr);
    }
    free(s);
}

void initLinkedStack(LinkedStack* s) {
     s->size = 0;
}

int fullLinkedList(LinkedStack* s) {
    return 0;
}

int emptyLinkedStack(LinkedStack* s) {
    if (s->size == 0) {
        return 1;
    }
    return 0;
}

char pushLinkedStack(LinkedStack* s, stackElement item) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = item;
    temp->next = s->head;
    s->head = temp;

    s->size++;
    return 1;
}

int popLinkedStack(LinkedStack* s) {
    if (!emptyLinkedStack(s)) {
        Node* tPtr=s->head;
        s->head = tPtr->next;
        free(tPtr);
        s->size--;
        return 1;

    }
    else {
        printf("Stack is empty");
        exit(1);
    }
}

int peekStack(LinkedStack* s) {
    if (!emptyLinkedStack(s)) {
        return s->head->data;
    }
    else {
        printf("Stack is empty");
        exit(1);
    }
}

void printLinkedStack(LinkedStack* s) {
    printf("Stack:\n"); 
    printf("Size: %d\n", s->size);

    Node* temp = s->head;
    while (temp != NULL) {
        printf("temp:%s\n", temp->data);
        temp = temp->next;
    }
}

