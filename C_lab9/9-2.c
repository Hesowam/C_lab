#include <stdio.h>
#include <stdlib.h>
void WordCount(char* string) {
    int count = 0;
    printf("\nSymbol after \":\" - ");
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == ':') {
            for (int j = i + 1; string[j] != '\0'; j++) {
                putchar(string[j]);
                if (string[j] != ' ') {
                    count++;
                }
            }
        }
    }
    printf("\nCount symbol after \":\" - %d", count);
}
int CountingLinesWithOddNum(char* str) {
    int counterWords = 0, counterString = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        int j = i;
        for (i = j; str[j] != '.'; j++) {
            if ((str[j + 1] == ',' || str[j + 1] == '.' || str[j + 1] == ' ') && (str[j] != ',' && str[j] != ' ' && str[j] != '.' && str[j] != '-')) {
                counterWords++;
            }
        }
        i = j;
        if (counterWords % 2 == 1) {
            counterString++;
        }
        counterWords = 0;
    }
    return counterString;
}
void main() {
    char* string;
    string = (char*)malloc(10 * sizeof(char));
    printf("Input string - \n");
    gets_s(string, 50);
    WordCount(string);
    printf("\nNumber of sentences containing an odd number of words - %d", CountingLinesWithOddNum(string));
}