#include<stdio.h>
#include<stdlib.h>

typedef int elementArrayList;

typedef struct arrayListType{
	elementArrayList* data;

	int size;
	int capacity;
}arrayList;

extern arrayList* createArrayList(int size);
extern void destroyArrayList(arrayList* al);
extern int isEmptyArrayList(arrayList* al);
extern int isFullArrayList(arrayList* al);
extern int sizeArrayList(arrayList* al);
extern int insertItemArrayList(arrayList* al, int pos, elementArrayList itme);
extern elementArrayList deleteItemArrayList(arrayList* al, int pos);
extern void initArrayList(arrayList* al);
extern elementArrayList getItemArrayList(arrayList* al, int pos);
extern int replaceItemArrayList(arrayList* al, int pos, elementArrayList Item);
extern void printArrayList(arrayList* al);
