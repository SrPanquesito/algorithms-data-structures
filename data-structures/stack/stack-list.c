#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// push, pop, top, isEmpty

typedef struct Node {
    int data;
    struct Node * next;
} Node;

Node * head;

void push(int data) {
    Node * temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void pop() {
    if (head != NULL) {
        Node * temp = head->next;
        free(head);
        head = temp;
    }
}

int top() {
    if (head != NULL) {
        return head->data;
    }
}

bool isEmpty() {
    if (head != NULL) {
        return false;
    } else {
        return true;
    }
}

int main() {
    head = NULL;
    push(1);
    push(2);
    push(3);
    pop();
    printf("%d\n", top());
    pop();
    printf("%d\n", top());
    pop();
    printf("%d\n", top());
    printf("%d\n", isEmpty());
    return 0;
}