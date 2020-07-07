#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

void enQueue(int, int *, int *, int *);
void deQueue(int *, int *, int *);
int isEmpty(int *, int *);
int isFull(int *, int *);
int front(int *, int *);


int main() {
    int arr[MAX_SIZE];
    int frontIndex = -1, backIndex = -1;

    printf("%d\n", isEmpty(&frontIndex, &backIndex));
    enQueue(10, arr, &frontIndex, &backIndex);
    enQueue(11, arr, &frontIndex, &backIndex);
    enQueue(12, arr, &frontIndex, &backIndex);
    enQueue(13, arr, &frontIndex, &backIndex);
    deQueue(arr, &frontIndex, &backIndex);
    enQueue(14, arr, &frontIndex, &backIndex);
    deQueue(arr, &frontIndex, &backIndex);
    deQueue(arr, &frontIndex, &backIndex);
    printf("%d\n", front(arr, &frontIndex));
    enQueue(15, arr, &frontIndex, &backIndex);
    enQueue(16, arr, &frontIndex, &backIndex);
    enQueue(17, arr, &frontIndex, &backIndex);
    enQueue(18, arr, &frontIndex, &backIndex);
    enQueue(19, arr, &frontIndex, &backIndex);
    enQueue(20, arr, &frontIndex, &backIndex);
    enQueue(21, arr, &frontIndex, &backIndex);
    enQueue(22, arr, &frontIndex, &backIndex);
    enQueue(23, arr, &frontIndex, &backIndex);
    enQueue(24, arr, &frontIndex, &backIndex);
    enQueue(25, arr, &frontIndex, &backIndex);

    printf("\n\n");
    for(int c=0; c < MAX_SIZE-1; c++) {
        printf("%d --- ", arr[c]);
    }
    

    return 0;
}

int front(int arr[], int * front) {
    return arr[*front];
}

int isEmpty(int * front, int * back) {
    if (*front == -1 && *back == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

void enQueue(int val, int arr[], int * front, int * back) {
    if (((*back+1) % MAX_SIZE) == *front) {
        printf("\nQueue is full.\n");
        return;
    }
    else if (isEmpty(front, back)) {
        *front = 0;
        *back = 0;
        arr[*back] = val;
    }
    else {
        *back = (*back + 1) % MAX_SIZE;
        arr[*back] = val;
    }
}

void deQueue(int arr[], int * front, int * back) {
    if (isEmpty(front, back)) {
        printf("\nQueue is empty. Can't remove value.\n");
        return;
    }
    else if (*front == *back) {
        *front = -1;
        *back = -1;
    }
    else {
        *front = (*front + 1) % MAX_SIZE;

        if (*front == *back) {
            *front = -1;
            *back = -1;
        }
    }
}