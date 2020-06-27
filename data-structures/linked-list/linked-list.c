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

void insertLastNode(Node * head) {
    Node * temp = (Node*)malloc(sizeof(Node));
    printf("Value number: ");
    scanf("%d", &(*temp).data);
    temp->next = NULL;

    while (head->next != NULL) {
        head = head->next;
    }
    head->next = temp;
}

Node * deleteNode(Node * head, int pos) {
    Node * node = head;
    Node * nextNode = node->next;
    int c = 0;

    if (pos > 0 && nextNode != NULL) {
        while (c < pos-1) {
            if (nextNode->next == NULL) break;
            node = nextNode;
            nextNode = nextNode->next;
            c++;
        }
        node->next = nextNode->next;
        free(nextNode);
    }
    else {
        head = node->next;
        free(node);
    }

    return head;
}

Node * reverseList(Node * head) {
    Node * prev = NULL, * current, * next;
    current = head;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

void insertNode(Node * node, int pos, int val) {
    if (pos != 0) {
        Node * temp = (Node*)malloc(sizeof(Node));
        temp->data = val;
        temp->next = NULL;

        for (int c=0; c < pos-1; c++) {
            if (node->next != NULL) node = node->next;
        }

        temp->next = node->next;
        node->next = temp;
    }
    else {
        printf("\n\n-----Position #0 is reserved for head. If you want to insert a new head please use option (1)-----\n\n");
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

    int op;
    while (op != 0) {
        printf("\nSelect an option: \n");
        printf("1) Insert head at the beggining. \n");
        printf("2) Insert node at the end. \n");
        printf("3) Insert node at # position. \n");
        printf("4) Delete node at # position. \n");
        printf("5) Reverse list. \n");
        printf("9) Print list. \n");
        printf("0) Exit. \n");
        if (scanf("%d", &op) != 1) {
            printf("\n");
            printf("Input is not a number.\n");
            return EXIT_FAILURE;
        } else {
            printf("\n");
            if (op == 1) {
                head = insertHead(head);
            }
            else if (op == 2) {
                if (head != NULL) {
                    insertLastNode(head);
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
            else if (op == 4) {
                if (head != NULL) {
                    int pos;
                    printf("Position #: ");
                    scanf("%d", &pos);
                    head = deleteNode(head, pos);
                }
                else {
                    printf("\n-----Define a head first.-----\n\n");
                }
            }
            else if (op == 5) {
                if (head != NULL) {
                    head = reverseList(head);
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
        
    }

    return 0;
}