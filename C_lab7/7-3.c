#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ScalarSumVectors(int **pInt, int column, int i, int j);

int inputColum() {
    const int column = 0;
    printf("Enter rows count:\t");
    scanf_s("%d", &column);
    return column;
}
int* initialArry(int** array, int column) {
    const int low = 0, hight = 2;
    srand((unsigned)time(0));
    for (int i = 0; i < column; i++) {
        for (int j = 0; j < column; j++) {
            array[i][j] = low + rand() % hight;
        }
    }
    return array;
}
int PrintMatrixArray(int** a, int col) {
    for (int i = 0; i < col; i++) {
        printf("\n");
        for (int j = 0; j < col; j++) {
            printf("%d\t", a[i][j]);
        }
    }
}
int CheckForOrthonormalMatrix(int** arr, int column) {
    int s = 0, j;
    for (int i = 0; i < column; i++) {
        j = i;
        s = ScalarSumVectors(arr, column, i, j);
        if (s != 1) { return printf("Matrix is not orthonormal."); }
        for (j = i + 1; j < column; j++) {
            s = ScalarSumVectors(arr, column, i, j);
            if (s != 0) { return printf("Matrix is not orthonormal."); }
        }
    }
    printf("Matrix is orthonormal.");
}

int ScalarSumVectors(int **pArray, int column, int i, int j) {
    int s = 0;
    for (int k = 0; k < column; k++) {
        s += pArray[i][k] * pArray[j][k];
    }
    return s;
}
int main() {
    const int col = inputColum();
    int* a = (int**)malloc(col * sizeof(int));
    for (int i = 0; i < col; i++) {
        a[i] = (int*)malloc(col * sizeof(int));
    }
    int* ar = initialArry(&a, col);
    CheckForOrthonormalMatrix(&ar, col);
    printf("\n");
    PrintMatrixArray(&ar, col);
    return 0;
}
