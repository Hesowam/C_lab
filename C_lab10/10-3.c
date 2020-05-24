#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
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
void PrintaArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf(" a[%d] - %d", i,a[i]);
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
        printf("\nВведіть а[%d]: ", i);
        if (!scanf("%d", &a[i])) {
            printf("\nПомилка. Захист від введення некоректних даних.\n");
            return -1;
        }
    }
    return a;
}
int main() {
    int* a;
    int n;
    printf("Enter n: \n");
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    if (a == NULL) printf("Помилка виділення пам'яті");
    //a = GenerateArray(a, n);
    a = InputArray(a, n);
    if (a == -1) return -1;
    printf("\nМасив - ");
    PrintaArray(a, n);
    printf("\nСума елементів масиву - %d", sumArray(a, n));
    printf("\nМінімальний елемент масиву - %d", FindTheMinimalElement(a, n));
    free(a, 0);
    return 0;
}