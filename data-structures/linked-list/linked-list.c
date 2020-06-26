#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node * next;
} Node;

Node * insertHead(Node * head) {
    Node * temp = (Node*)malloc(sizeof(Node));
    printf("Value number: ");
    scanf("%d", &(*temp).data);
    temp->next = head;
    return temp;
}

Node * insertLastNode(Node * head, Node * lastnode) {
    Node * temp = (Node*)malloc(sizeof(Node));
    printf("Value number: ");
    scanf("%d", &(*temp).data);
    temp->next = NULL;

    if (lastnode == NULL) {
        while (head->next != NULL) {
            head = head->next;
        }
        head->next = temp;
    }
    else {
        lastnode->next = temp;
    }

    return temp;
}

void insertNode(Node * current_node, int pos, int val) {
    if (pos != 0) {
        Node * temp = (Node*)malloc(sizeof(Node));
        temp->data = val;
        temp->next = NULL;

        for (int c=0; c < pos-1; c++) {
            if (current_node->next != NULL) current_node = current_node->next;
        }

        temp->next = current_node->next;
        current_node->next = temp;
    }
    else {
        printf("\n\n---Position #0 is reserved for head. If you want to insert a new head please use option (1)---\n\n");
    }
}

void insertNodeMenu(Node * head) {
    int pos, val;
    printf("Position #: ");
    scanf("%d", &pos);
    printf("Value number: ");
    scanf("%d", &val);
    insertNode(head, pos, val);
}

void printList(Node * head) {
    printf("\n\n");
    printf("-----List be like:-----\n");
    while (head->next != NULL) {
        printf("%d - ", head->data);
        head = head->next;
    }
    printf("%d", head->data);
    printf("\n\n\n");
}

int main() {
    Node * head = NULL;
    Node * lastnode = NULL;

    int op;
    while (op != 0) {
        printf("\nSelect an option: \n");
        printf("1) Insert head at the beggining. \n");
        printf("2) Insert node at the end. \n");
        printf("3) Insert node at # position. \n");
        printf("9) Print list. \n");
        printf("0) Exit. \n");
        scanf("%d", &op);
        printf("\n");
        
        if (op == 1) {
            head = insertHead(head);
        }
        else if (op == 2) {
            if (head != NULL) {
                lastnode = insertLastNode(head, lastnode);
            }
            else {
                printf("\n-----Define a head first.-----\n\n");
            }
        }
        else if (op == 3) {
            if (head != NULL) {
                insertNodeMenu(head);
            }
            else {
                printf("\n-----Define a head first.-----\n\n");
            }
        }
        else if (op == 9) {
            if (head != NULL) {
                printList(head);
            }
            else {
                printf("\n-----Define a head first.-----\n\n");
            }
        }
        else if (op != 0) {
            printf("\n-----Please insert a valid option.-----\n\n");
        }
    }

    return 0;
}