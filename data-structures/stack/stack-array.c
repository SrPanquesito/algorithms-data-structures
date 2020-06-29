#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 11

// push, pop, top, isEmpty
// All values of an int array are 0 by default

int array[MAX_SIZE];
int top = -1;

void Push(int data) {
    if (top == MAX_SIZE-1) {
        printf("Array maxed out!\n");
        return;
    }
    array[++top] = data;
}

void Pop() {
    if (top == -1) {
        return;
    }
    array[top--] = 0;
}

int Top() {
    return array[top];
}

bool isEmpty() {
    if (top == -1) {
        return true;
    }
    else {
        return false;
    }
}

int main () {
    printf("%d\n", isEmpty());
    Push(2);
    printf("%d\n", isEmpty());
    Push(4);
    printf("%d\n", Top());
    Pop();
    printf("%d\n", Top());
    Pop();
    printf("%d\n", Top());
    return 0;
}