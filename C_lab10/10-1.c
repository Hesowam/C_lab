#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>

int GenerateArray(int* a,int n) {
    const int max = 100, min = -100;
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++) {
        a[i] = min + rand() % (max - min + 1);
    }
    return a;
}
int sumArray(int* a, int n ) {
    --n;
    if (n < 0) {
        return 0;
    }
    return (sumArray(a, n)+a[n]);
}
void PrintArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf(" a[%d] - (%d)", i,a[i]);
    }
}
int FindTheMinimalElement(int* a, int n) {
    int Low = 100;
    for (int i = 0; i < n; i++){
        if (Low > a[i]) Low = a[i];
    }
    return Low;
}
int InputArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nInput а[%d]: ", i);
        if (!scanf("%d", &a[i])) {
            printf("\nError. IsInt = false\n");
            return -1;
        }
    }
    return a;
}
int main() {
    int n;
    printf("Enter n: \n");
    scanf("%d", &n);
    int * a = (int*)malloc(n * sizeof(int));
    if (a == NULL) printf("Dynamic memory error");
    a = GenerateArray(a, n);
    //a = InputArray(a, n);
    if (a == -1) return -1;
    printf("\nArray - ");
    PrintArray(a, n);
    printf("\nThe sum of the elements of the array - %d", sumArray(a, n));
    printf("\nMinimal element of the array - %d", FindTheMinimalElement(a, n));
    free(a);
    return 0;
}