#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>

int Matrix(int** a, int n, int m) {
    const int min = -100, max = 100;
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = min + rand() % (max - min + 1);
        }
    }
    return a;
}
void PrintMatrixArray(int** a, int n, int m) {
    for (int i = 0; i < n; i++) {
        printf("\n");
        for (int j = 0; j < m; j++) {
            printf(" A[%d][%d] - %d", i, j, a[i][j]);
        }
    }
}
int Swap(int** a, int m, int k, int p) {
    --m;
    int buf;
    buf = a[k - 1][m];
    a[k - 1][m] = a[p - 1][m];
    a[p - 1][m] = buf;
    buf = NULL;
    if (m < 0) return a;
    return Swap(a, m, k, p);
}
int KeyboardInputArray(int** a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Enter a[%d][%d]- ", i, j);
            if (!scanf("%d", &a[i][j])) return -2;
        }
    }
    return a;
}
int main() {
    printf("Enter column count: ");
    int m, n, k = NULL, p = NULL;
    scanf("%d", &m);
    printf("Enter rows count: ");
    scanf("%d", &n);
    int** a = (int*)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("\nError dynamic memory.\n");
        return -1;
    }
    for (int i = 0; i < n; i++) {
        a[i] = (int*)malloc(m * sizeof(int));
        if (a == NULL) {
            printf("\nError dynamic memory.\n");
            return -1;
        }
    }
    //a = Matrix(a, n, m);
    a = KeyboardInputArray(a, n, m);
    printf("\nArray: ");
    PrintMatrixArray(a, n, m);
    while (k == NULL || k<0 || k>n){
        printf("\n\nInput k: ");
        scanf("%d", &k);
    }
    while (p == NULL || p<0 || p>n){
        printf("Input p: ");
        scanf("%d", &p);
    }
    printf("\nChanged array p: ");
    PrintMatrixArray(Swap(a, m, k, p), n, m);
    for (int i = 0; i < n; i++){
        free(a[i]);
    }
    free(a);
    return 0;
}