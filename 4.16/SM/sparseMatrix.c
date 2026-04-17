#include<stdio.h>
#include<stdlib.h>

#include "sparseMatrix.h"

sparseMatrix* createSparseMatrix(int row, int col) {
    sparseMatrix* sm = (sparseMatrix*)malloc(sizeof(sparseMatrix));

    sm->row = row;
    sm->col = col;
    sm->list = createArrayList(20);

    return sm;
}

void addElementSparseMatrix(sparseMatrix* sm, int row, int col, int value) {
    if (value == 0) return;

    insertItemArrayList(sm->list,
        sizeArrayList(sm->list),
        (elementArrayList) {
        row, col, value
    });
}

void printSparseMatrix(sparseMatrix* sm) {
    printf("(%d x %d) Sparse Matrix\n", sm->row, sm->col);
    printArrayList(sm->list);
}

sparseMatrix* transposeSparseMatrix(sparseMatrix* sm, int* moveCount) {
    sparseMatrix* result = createSparseMatrix(sm->col, sm->row);

    *moveCount = 0;

    for (int i = 0; i < sizeArrayList(sm->list); i++) {
        elementArrayList e = getItemArrayList(sm->list, i);

        elementArrayList t = { e.col, e.row, e.value };

        insertItemArrayList(result->list,
            sizeArrayList(result->list),
            t);

        (*moveCount)++;
    }

    return result;
}
