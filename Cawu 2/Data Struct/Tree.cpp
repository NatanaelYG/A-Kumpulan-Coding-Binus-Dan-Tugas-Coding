#include <stdlib.h>
#include <stdio.h>

typedef struct Data{
    int data;
    struct Data *left, *right;
} Node;

Node *root = NULL;

Node *createNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insert(Node *newNode, Node *curr = root){
    if(curr == NULL) 
        return newNode;
    else if(newNode->data > curr->data)
        curr->right = insert(newNode, curr->right);
    else if(newNode->data < curr->data)
        curr->left = insert(newNode, curr->left);
        return curr;
}

Node *deleted(Node* root, int key){
    if (root == NULL) {
        return root;
    }
    
    if(root->data > key) {
        root->left =  deleted(root->left, key);
        return root;
    } else if(root->data < key) {
        root->right =  deleted(root->right, key);
        return root;
    }
    
    if (root->left == NULL) {
        Node* temp = root->right;
        free(root);
        return temp;
    } else if (root->right == NULL) {
        Node *temp = root->left;
        free(root);
        return temp;
    } else {
        Node* succParent = root;

        Node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }

        if (succParent != root){
            succParent->left = succ->right;
        } else {
            succParent->right = succ->right;
        }

        root->data = succ->data;

        free(succ);
        return root;
    }
}

void inOrder(Node *curr = root){
    if(curr){
        inOrder(curr->left);
        printf("%d ", curr->data);
        inOrder(curr->right);
    }
}

Node *maxValue(Node *curr = root) {
    while (curr->right != NULL) {
        curr = curr->right;
    }
    printf("Max Value: %d\n", curr->data);
}

Node *minValue(Node *curr = root) {
    while (curr->left != NULL) {
        curr = curr->left;
    }
    printf("Min Value: %d\n", curr->data);
}

int main(){

    root = insert(createNode(10));
    root = insert(createNode(8));
    root = insert(createNode(7));
    root = insert(createNode(9));
    root = insert(createNode(6));
    root = insert(createNode(13));
    root = insert(createNode(12));
    root = insert(createNode(11));
    root = insert(createNode(15));
    root = insert(createNode(14));

    printf("=============\n");
    printf("  InOrder\n");
    printf("=============\n");
    inOrder();
    printf("\n");

    root = deleted(root, 7);
    printf("\n");
    inOrder();

    root = deleted(root, 14);
    printf("\n");
    inOrder();

    root = insert(createNode(17));
    printf("\n");
    inOrder();
    
    root = deleted(root, 13);
    printf("\n");
    inOrder();
    printf("\n");


    maxValue(root);

    minValue(root);

    return 0;
}