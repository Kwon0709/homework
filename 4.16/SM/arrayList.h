#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int value;
} elementArrayList;

typedef struct {
    int size;
    int capacity;
    elementArrayList* data;
} arrayList;

arrayList* createArrayList(int size);
void destroyArrayList(arrayList* al);

int isEmptyArrayList(arrayList* al);
int isFullArrayList(arrayList* al);
int sizeArrayList(arrayList* al);

int insertItemArrayList(arrayList* al, int pos, elementArrayList item);
int deleteItemArrayList(arrayList* al, int pos);
void initArrayList(arrayList* al);

elementArrayList getItemArrayList(arrayList* al, int pos);
int replaceItemArrayList(arrayList* al, int pos, elementArrayList item);

void printArrayList(arrayList* al);
