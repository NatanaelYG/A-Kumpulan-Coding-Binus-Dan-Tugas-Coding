#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    int height;
    struct node* left;
    struct node* right;
} node;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(node* n) {
    if (n == NULL) {
        return -1;
    }
    return n->height;
}

node* newNode(int key) {
    node* n = (node*)malloc(sizeof(node));
    n->key = key;
    n->height = 0;
    n->left = NULL;
    n->right = NULL;
    printf("Key : %d, Height : %d\n", n->key, n->height);
    return n;
}

node* rightRotate(node* y) {
    node* x = y->left;
    node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

node* leftRotate(node* x) { 
    node* y = x->right;
    node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(node* n) {
    if (n == NULL) {
        return 0;
    }
    return height(n->left) - height(n->right);
}

node* insert(node* n, int key) {
    if (n == NULL) {
        return newNode(key);
    }
    if (key < n->key) {
        n->left = insert(n->left, key);
    }
    else if (key > n->key) {
        n->right = insert(n->right, key);
    }
    else {
        return n;
    }
    n->height = max(height(n->left), height(n->right)) + 1;
    int balance = getBalance(n);
    printf("Key : %d, Height : %d\n", n->key, n->height);
    
    if (balance > 1 && key < n->left->key) {
    	printf("Case 1\n");
        return rightRotate(n);
    }
    if (balance < -1 && key > n->right->key) {
    	printf("Case 2\n");
        return leftRotate(n);
    }
    if (balance > 1 && key > n->left->key) {
    	printf("Case 3\n");
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }
    if (balance < -1 && key < n->right->key) {
    	printf("Case 4\n");
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }
    return n;
}

void preOrder(node* n) {
    if (n != NULL) {
        printf("%d ", n->key);
        preOrder(n->left);
        preOrder(n->right);
    }
}

node* minValueNode(node* n) {
    node* current = n;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

node* deleteNode(node* n, int key) {
    if (n == NULL) {
        return n;
    }
    if (key < n->key) {
        n->left = deleteNode(n->left, key);
    }
    else if (key > n->key) {
        n->right = deleteNode(n->right, key);
    }
    else {
        if ((n->left == NULL) || (n->right == NULL)) {
            node* temp = n->left ? n->left : n->right;
            if (temp == NULL) {
                temp = n;
                n = NULL;
            }
            else {
                *n = *temp;
                free(temp);
            }
        }
        else {
            node* temp = minValueNode(n->right);
            n->key = temp->key;
            n->right = deleteNode(n->right, temp->key);
        }
    }
    if (n == NULL) {
        return n;
    }
    n->height = max(height(n->left), height(n->right)) + 1;
    int balance = getBalance(n);
    if (balance > 1 && getBalance(n->left) >= 0) {
        return rightRotate(n);
    }
    if (balance > 1 && getBalance(n->left) < 0) {
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }
    if (balance < -1 && getBalance(n->right) <= 0) {
        return leftRotate(n);
    }
    if (balance < -1 && getBalance(n->right) > 0) {
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }
    return n;
}


int main() {
    node* root = NULL;
//    root = insert(root, 10);
//    root = insert(root, 20);
//    root = insert(root, 30);
//    root = insert(root, 40);
//    root = insert(root, 50);
//    root = insert(root, 25);
	root = insert(root, 50);
	root = insert(root, 40);
	root = insert(root, 45);
    printf("Preorder traversal of the constructed AVL tree is: \n");
    preOrder(root);
    
    // Delete some keys
//    root = deleteNode(root, 30);
//    root = deleteNode(root, 40);

    // Print the tree again
//    printf("\nTree after deleting 30 and 40:\n");
//    preOrder(root);
//    
    return 0;
}

