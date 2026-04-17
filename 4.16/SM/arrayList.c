#include "arrayList.h"

arrayList* createArrayList(int size) {
    arrayList* al = (arrayList*)malloc(sizeof(arrayList));

    al->capacity = size;
    al->size = 0;
    al->data = (elementArrayList*)malloc(sizeof(elementArrayList) * size);

    return al;
}

void destroyArrayList(arrayList* al) {
    if (al) {
        free(al->data);
        free(al);
    }
}

int isEmptyArrayList(arrayList* al) {
    return (al->size == 0);
}

int isFullArrayList(arrayList* al) {
    return (al->size == al->capacity);
}

int sizeArrayList(arrayList* al) {
    return al->size;
}

int insertItemArrayList(arrayList* al, int pos, elementArrayList item) {
    if (isFullArrayList(al)) return 0;
    if (pos < 0 || pos > al->size) return 0;

    for (int i = al->size; i > pos; i--) {
        al->data[i] = al->data[i - 1];
    }

    al->data[pos] = item;
    al->size++;

    return 1;
}

int deleteItemArrayList(arrayList* al, int pos) {
    if (pos < 0 || pos >= al->size) return 0;

    for (int i = pos; i < al->size - 1; i++) {
        al->data[i] = al->data[i + 1];
    }

    al->size--;

    return 1;
}

void initArrayList(arrayList* al) {
    al->size = 0;
}

elementArrayList getItemArrayList(arrayList* al, int pos) {
    return al->data[pos];
}

int replaceItemArrayList(arrayList* al, int pos, elementArrayList item) {
    if (pos < 0 || pos >= al->size) return 0;

    al->data[pos] = item;
    return 1;
}

void printArrayList(arrayList* al) {
    for (int i = 0; i < al->size; i++) {
        elementArrayList e = al->data[i];
        printf("(%d, %d) = %d\n", e.row, e.col, e.value);
    }
}
