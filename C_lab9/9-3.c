#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>

char** RandomStingArryGenerator(int n, int MaxStirngSize, int LowStringSize) {// n- count string
    char** str;
    str = (char**)malloc(100 * sizeof(char**));
    for (int i = 0; i <= n; i++) {
        str[i] = (char*)malloc(100 * sizeof(char*));
    }
    srand((unsigned)time(NULL));
    char chars[26];
    for (int i = 65, n = 0; i <= 90; ++i, n++) {
        chars[n] = (char)i;
    }
    for (int i = 0; i < n; i++) {
        int randomValue = LowStringSize + rand() % (MaxStirngSize - LowStringSize + 1);
        for (int j = 0; j <= randomValue; j++) {
            if (j == randomValue) {
                str[i][j] = '\0';
            }
            else {
                str[i][j] = chars[(0 + rand() % (26 - 1 + 1))];
            }
        }
    }
    return str;
}

int PrintArray(char** str, int n) {
    for (int i = 0; i < n; i++) {
        printf("\n");
        for (int j = 0; str[i][j] != '\0'; j++) {
            putchar(str[i][j]);
        }
    }
    return 0;
}
char** ReturnChangedArray(char** str, int n, int i) {
    int d = ++i;
    if (strlen(str[i]) % 3 == 0) {
        if (++i > n) {
            d = 0;
        }
        for (int j = 0; j < 5; j++) {
            str[i][j] = str[d][j];
        }
        str[i][5] = '\0';
        return str;
    }
    else if (i >= n) {
        return "false";
    }
    else {
        return ReturnChangedArray(str, n, i++);
    }
}
int main() {
    char** Str;
    int n = 10;
    Str = RandomStingArryGenerator(n, 79, 10);
    printf("\nGenerated string array:\n");
    PrintArray(Str, n);
    printf("\n\nChanged array:\n");
    if (ReturnChangedArray(Str, n, 0) == "false") {
        printf("There is no row in the array with the number of elements multiples of three.\n");
    }
    else {
        PrintArray(ReturnChangedArray(Str, n, 0), n);
    }
    return 0;
}