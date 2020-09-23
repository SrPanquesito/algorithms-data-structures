#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 11

int main() {
    int op1 = 3, op2 = 5, res;

    // For base 2 any previous number in binary is a complement of the current number
    // 16 => 1 0000
    // 15 => 0 1111
    // Apply AND operator
    if ((op2 != 0) && (op2 & (op2-1) == 0)) {
        
    } else {

    }

    printf("%d", x);

    return 0;
}