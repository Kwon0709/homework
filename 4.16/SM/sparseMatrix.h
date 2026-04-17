#include<stdio.h>
#include<stdlib.h>

#include "arrayList.h"

typedef struct {
    int row;
    int col;
    arrayList* list;
} sparseMatrix;

sparseMatrix* createSparseMatrix(int row, int col);
void addElementSparseMatrix(sparseMatrix* sm, int row, int col, int value);
void printSparseMatrix(sparseMatrix* sm);
sparseMatrix* transposeSparseMatrix(sparseMatrix* sm, int* moveCount);
