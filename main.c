#include<stdio.h>
#include<stdlib.h>

#include"LinkedStack.h"

int main() {
    LinkedStack* myStack = createLinkedStack();

    pushLinkedStack(myStack, 10);
    pushLinkedStack(myStack, 20);
    pushLinkedStack(myStack, 30);

    printLinkedStack(myStack);

    return 0;
}