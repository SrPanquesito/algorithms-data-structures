#include <stdio.h>
#include <stdlib.h>

int F[200];

int factorial(int n) {
    if (n == 0) return 1;
    return n*factorial(n-1);
}

int fibonacci(int pos) {
    if (pos == 0) return 0;
    if (pos == 1) return 1;
    if (F[pos] != 0) return F[pos];

    F[pos] = fibonacci(pos-1) + fibonacci(pos-2);
    return F[pos];
}

int main() {
    int x;
    scanf("%d", &x);
    // printf("%d", factorial(x));
    for (int c = 0; c < x; c++) {
        printf("%d -- ", fibonacci(c));
    }
    return 0;
}