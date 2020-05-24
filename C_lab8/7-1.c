#include <stdio.h>
int* sort(int* arr, int countColums) {
    int max = 0;
    for (int i = 0; i <= countColums; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    for (int i = 0; i < countColums; i++) {
        if (arr[i] < 0) {
            arr[i] = max;
        }
    }
    return arr;
}
int main(void) {
    const int countColums = 6;
    int a[] = { 6,-63,12,-33,77,24 };
    int* p = sort(a, countColums);
    for (int i = 0; i < countColums; i++) {
        printf("%d ", p[i]);
    }
    return 0;
}