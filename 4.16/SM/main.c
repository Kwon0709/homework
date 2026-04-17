#include <stdio.h>
#include "sparseMatrix.h"

int main() {
    sparseMatrix* sm = createSparseMatrix(10, 10);

    for (int i = 0; i < 20; i++) {
        addElementSparseMatrix(sm, i % 10, (i * 2) % 10, i + 1);
    }

    printf("=== 원본 ===\n");
    printSparseMatrix(sm);

    int moveCount;
    sparseMatrix* trans = transposeSparseMatrix(sm, &moveCount);

    printf("\n=== 전치 ===\n");
    printSparseMatrix(trans);

    printf("\n이동 횟수: %d\n", moveCount);

    destroyArrayList(sm->list);
    destroyArrayList(trans->list);
    free(sm);
    free(trans);

    return 0;
}
