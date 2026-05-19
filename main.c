#include<stdio.h>
#include<stdlib.h>

#include"LinkedStack.h"

int main() {
    LinkedStack* myStack = createLinkedStack();

    pushLinkedStack(myStack, "www.google.com");
    pushLinkedStack(myStack, "www.naver.com");
    pushLinkedStack(myStack, "dkmd");

    printLinkedStack(myStack);

    popLinkedStack(myStack);

    printLinkedStack(myStack);

    printf("peek:%d", peekStack(myStack));

    return 0;
}