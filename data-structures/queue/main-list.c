#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node * next;
} Node;
Node * front = NULL;
Node * rear = NULL;

void enQueue(int);
void deQueue();
int frontValue();
int isEmpty();

int main() {

    enQueue(2);
    printf("%d\n", frontValue());
    enQueue(4);
    enQueue(6);
    enQueue(8);
    deQueue();
    printf("%d\n", frontValue());
    deQueue();
    printf("%d\n", frontValue());
    deQueue();
    printf("%d\n", isEmpty());
    deQueue();
    printf("%d\n", isEmpty());

    return 0;
}

void enQueue(int data) {
    Node * temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if (front == NULL && rear == NULL) {
        front = rear = temp;
    }
    else {
        rear->next = temp;
        rear = temp;
    }
}

void deQueue() {
    Node * temp = front;
    if (isEmpty()) {
        printf("\nList is empty.\n");
        return;
    }
    else if (front == rear) {
        front = NULL;
        rear = NULL;
    }
    else {
        front = front->next;
    }
    free(temp);
}

int frontValue() {
    if (front != NULL) {
        return front->data;
    }
}

int isEmpty() {
    if ((front == NULL && rear == NULL)) {
        return 1;
    } else {
        return 0;
    }
}