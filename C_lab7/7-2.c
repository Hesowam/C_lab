#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int inputColumn() {
    int column = NULL;
    while (column == NULL || column<=0){
        printf("Enter numbers count: ");
        scanf_s("%d", &column);
    }
    return column;
}
int* initialArray(int* array, int column) {
    const int low = -100, height = 100;
    srand((unsigned)time(0));
    for (int i = 0; i <= column; i++) {
        *(array+i) = low + rand() % (height - low + 1);
    }
    return array;
}
int PrintArray(int* a, int col) {
    for (int i = 0; i < col; i++) {
        printf("\t%d", a[i]);
    }
}
int GetMinArraySum(int* arr, int column) {
    int sum = 0;
    for (int i = 0; i <= column; i++)
    {
        if (*(arr+i) < 0 && *(arr + i + 1)>0) {
            while (*(arr + i + 1) > 0)
            {
                sum += *(arr + i + 1);
                i++;
            }
            break;
        }
    }
    return sum;
}
int findMinElementOfArray(int* arr, int column) {
    int min = 0;
    for (int i = 0; i < column; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
int main() {
    const int col = inputColumn();
    int* a = (int*)malloc(col + 1);
    int* ar = initialArray(a, col);
    printf("Generated array:");
    PrintArray(ar, col);
    printf("\nThe sum between the first two negative elements - %d", GetMinArraySum(ar, col));
    printf("\nMinimal array element - %d", findMinElementOfArray(ar, col));
    return 0;
}