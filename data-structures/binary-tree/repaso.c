#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node * left;
    struct Node * right;
} Node;

Node * getNewNode(int);
void insertNode(Node **, int);
void preOrder(Node *);
int search(Node *, int);

Node * getNewNode(int data) {
    Node * temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void insertNode(Node ** root, int data) {
    if (*root == NULL) {
        *root = getNewNode(data);
    }
    else if (data <= (*root)->data) {
        insertNode(&(*root)->left ,data);
    }
    else {
        insertNode(&(*root)->right ,data);
    }
    return;
}

int search(Node * root, int data) {
    if (root == NULL) return 0;
    if (root->data == data) return 1;
    if (data <= root->data) return search(root->left, data);
    else return search(root->right, data);
}

void preOrder(Node * root) {
    if (root == NULL) return;
    printf("%d\n", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node * root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d\n", root->data);
}

int isBinarySearchTree(Node * root, int minValue, int maxValue) {
    if (root == NULL) return 1;
    if (root->data > minValue &&
        root->data <= maxValue &&
        isBinarySearchTree(root->left, minValue, root->data) &&
        isBinarySearchTree(root->right, root->data, maxValue)) 
        return 1;
    else return 0;
}


/*
    if (x < root->data && y < root->data) lowerCommonAncestor(root->left, x, y)
    if (x > root->data && y > root->data) lowerCommonAncestor(root->right, x, y)
    return root
*/
Node * lowestCommonAncestor(Node * root, int x, int y) {
    if (root == NULL) return root;
    if (root->data == x || root->data == y) return root;

    Node * tempLeft = lowestCommonAncestor(root->left, x, y);
    Node * tempRight = lowestCommonAncestor(root->right, x, y);

    if (tempLeft == NULL) return tempRight;
    if (tempRight == NULL) return tempLeft;
    return root;
}

Node * findMaxNode(Node * current) {
    if (current->right == NULL) return current;
    return findMaxNode(current->right);
}

Node * deleteNode(Node * root, int data) {
    if (data < root->data) root->left = deleteNode(root->left, data);
    else if (data > root->data) root->right = deleteNode(root->right, data);
    // Node Found
    else {
        // Case 1 (No childs)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Case 2 (One child)
        else if (root->left == NULL) {
            Node * temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL) {
            Node * temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3 (Two childs)
        else {
            Node * leftMax = findMaxNode(root->left);
            root->data = leftMax->data;
            root->left = deleteNode(root->left, leftMax->data);
        }
        return root;
    }
}

int* preorderTraversal(struct Node* root, int returnSize){
    int * arr = (int*)malloc(returnSize * sizeof(int));
    int c = 0;
    struct Node * current = root;
    
    while (c < returnSize) {
        arr[c] = current->data; // n
        if (current->left) {
            current = current->left;
            c++;
        } // l
        else if (current->right) {
            current = current->right;
            c++;
        } // r
    }
    
    return arr;
}

int main() {
    Node * root = NULL;

    insertNode(&root, 1);
    insertNode(&root, 2);
    insertNode(&root, 3);

    int z = 3;
    int *p = preorderTraversal(root, z);
    for (int i = 0; i < z; i++ ) {
      printf( "*(p + %d) : %d\n", i, *(p + i));
   }

    insertNode(&root, 10);
    insertNode(&root, 4);
    insertNode(&root, 3);
    insertNode(&root, 2);
    insertNode(&root, 12);
    insertNode(&root, 15);
    insertNode(&root, 11);

    preOrder(root);
    printf("\n");
    postOrder(root);

    printf("\n\n%d\n", search(root, 13));

    printf("\n%d\n", isBinarySearchTree(root, INT_MIN, INT_MAX));

    int x = 2;
    int y = 3;
    Node * lca = lowestCommonAncestor(root, x, y);
    printf("\nLowest common ancestor of %d and %d is root with value: %d\n", x, y, lca->data);

    root = deleteNode(root, 12);
    preOrder(root);
    printf("\n");
    postOrder(root);

    return 0;
}