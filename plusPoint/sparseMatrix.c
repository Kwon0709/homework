#include <stdio.h>
#include <stdlib.h>

#include "sparseMatrix.h"

sparseMatrix* createSparseMatrix(int row, int col) {
	return createArrayList(row * col);
}

int addElementSparseMatrix(sparseMatrix* sm, int row, int col, int value) {
    int size = sizeArrayList(sm);
    return insertArrayList(sm, size, (elementArrayList){row, col, value});
}

void printSparseMatrix(sparseMatrix* sm) {
    printf("희소행렬입니다.\n");
    printArrayList(sm);
}

sparseMatrix* addSparseMatrix(sparseMatrix* sm1, sparseMatrix* sm2) {
    sparseMatrix* smResult = createArrayList(sizeArrayList(sm1) + sizeArrayList(sm2));

    // sm1 순회: sm2에 같은 위치 있으면 합산, 없으면 그냥 추가
    for (int i = 0; i < sizeArrayList(sm1); i++) {
        elementArrayList nonZeroOfSM1 = getItemArrayList(sm1, i);
        int j;
        for (j = 0; j < sizeArrayList(sm2); j++) {
            elementArrayList nonZeroOfSM2 = getItemArrayList(sm2, j);
            if (nonZeroOfSM1.row == nonZeroOfSM2.row &&
                nonZeroOfSM1.col == nonZeroOfSM2.col) {
                insertArrayList(smResult, sizeArrayList(smResult), (elementArrayList){
                    nonZeroOfSM1.row,
                    nonZeroOfSM1.col,
                    nonZeroOfSM1.value + nonZeroOfSM2.value
                });
                break;
            }
        }
        if (j == sizeArrayList(sm2)) {  // sm2에 없던 sm1 원소 추가
            insertArrayList(smResult, sizeArrayList(smResult), nonZeroOfSM1);
        }
    }

    // sm2 순회: sm1에 없는 원소만 추가
    for (int j = 0; j < sizeArrayList(sm2); j++) {
        elementArrayList nonZeroOfSM2 = getItemArrayList(sm2, j);
        int found = 0;
        for (int i = 0; i < sizeArrayList(sm1); i++) {
            elementArrayList nonZeroOfSM1 = getItemArrayList(sm1, i);
            if (nonZeroOfSM1.row == nonZeroOfSM2.row &&
                nonZeroOfSM1.col == nonZeroOfSM2.col) {
                found = 1;
                break;
            }
        }
        if (!found) {  // sm1에 없던 sm2 원소 추가
            insertArrayList(smResult, sizeArrayList(smResult), nonZeroOfSM2);
        }
    }

    return smResult;
}
