#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node * left;
    struct Node * right;
} Node;

Node * getNewNode(int);
Node * insertNode(Node *, int);
int search(Node *, int);


Node * getNewNode(int data) {
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node * insertNode(Node * root, int data) {
    if (root == NULL) {
        root = getNewNode(data);
    }
    else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

int search(Node * root, int data) {
    //if (root != NULL) printf("%d\n", root->data);
    if (root == NULL) return 0;
    else if (root->data == data) return 1;
    else if (data <= root->data) return search(root->left, data);
    else return search(root->right, data);
}

int minVal(Node * current) {
    if (current->left == NULL) {
        return current->data;
    }
    else {
        return minVal(current->left);
    }
}

int maxVal(Node * current) {
    if (current->right == NULL) {
        return current->data;
    }
    else {
        return maxVal(current->right);
    }
}

int maxCompare(int v1, int v2) {
    if (v1 <= v2) {
        return v2;
    }
    else {
        return v1;
    }
}

// Still don't get the maxCompare func. recursion
int findHeight(Node * current) {
    if (current == NULL) {
        return -1;
    }
    return maxCompare(findHeight(current->left), findHeight(current->right)) + 1;
}

// DLR
void preOrder(Node * node) {
    if (node == NULL) return;
    printf("%d\n", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

// LDR
void inOrder(Node * node) {
    if (node == NULL) return;
    inOrder(node->left);
    printf("%d\n", node->data);
    inOrder(node->right);
}

// LRD
void postOrder(Node * node) {
    if (node == NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    printf("%d\n", node->data);
}

int main() {
    Node * root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 15);
    root = insertNode(root, 8);
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 3);
    
    printf("%d\n", search(root, 20));

    printf("%d\n", minVal(root));
    printf("%d\n", maxVal(root));
    
    printf("Height: %d\n", findHeight(root));

    return 0;
}
