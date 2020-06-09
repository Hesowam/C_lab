#include <stdio.h>

int Factorial(int n) {
    if (n <= 1) return 1;
    return (n * Factorial(n - 1));
}

int Counting(int n) {
    return Factorial(n) / (Factorial(2) * Factorial(n - 2));
}

int main() {
    printf("%d - straight lines can be drawn through 8 points, of which no three lie on one straight line.\n", Counting(8));
    return 0;
}
