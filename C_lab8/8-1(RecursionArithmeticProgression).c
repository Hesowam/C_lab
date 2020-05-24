#include <stdio.h>
#include <locale.h>
#include "windows.h"

int ArithmeticProgression(int a1,int d, int n) {
    if (n <= 0) { return a1-d; }
    else{return (ArithmeticProgression(a1+d,d,--n));}
}
void main() {
    setlocale(LC_CTYPE, "ukr");
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    int a1,d,n,value;
    printf("Enter the first term of the arithmetic progression:\t");
    scanf_s("%d", &a1);
    printf("Enter the difference of the arithmetic progression:\t");
    scanf_s("%d", &d);
    printf("Enter the n term of the arithmetic progression:\t");
    scanf_s("%d", &n);
    value = ArithmeticProgression(a1,d,n);
    printf("\nA[%d] term of the arithmetic progression = %d",d,value);
}