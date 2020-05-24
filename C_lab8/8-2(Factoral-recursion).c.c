#include <stdio.h>
#include <stdlib.h>
int Counting(int n) {
    int c;
    c = Factorial(n) / (Factorial(2) * Factorial(n - 2));
}
int Factorial(int n) {
    if (n <= 1) { return 1; }
    else { return (n * Factorial(n - 1)); }
}

void main() {
    printf("%d - straight lines can be drawn through 8 points, of which no three lie on one straight line.\n", Counting(8));
}