#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Mahasiswa {
    char name[50];
    char nim[12];
    int age;
    struct Mahasiswa *left, *right;
} Node;

Node *root = NULL;

Node *createNode(const char* name, const char* nim, int age){
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->nim, nim);
    newNode->age = age;

    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insertion(Node *newNode, Node *curr = root){
    if(curr == NULL) 
        return newNode;
    else if(strcmp(newNode->name, curr->name) > 0)
        curr->right = insertion(newNode, curr->right);
    else if(strcmp(newNode->name, curr->name) < 0)
        curr->left = insertion(newNode, curr->left);
        return curr;
    
}

void preOrder(Node *curr = root){
    if(curr) {
        printf("Name : %s\nNIM : %s\nAge : %d\n\n",curr->name, curr->nim, curr->age);
        preOrder(curr->left);
        preOrder(curr->right);
    }
}

void inOrder(Node *curr = root){
    if(curr) {
        inOrder(curr->left);
        printf("Name : %s\nNIM : %s\nAge : %d\n\n",curr->name, curr->nim, curr->age);
        inOrder(curr->right);
    }
}

void postOrder(Node *curr = root){
    if(curr) {
        postOrder(curr->left);
        postOrder(curr->right);
        printf("Name : %s\nNIM : %s\nAge : %d\n\n",curr->name, curr->nim, curr->age);
    }
}

Node *searching(const char* name, Node *curr = root){
    if(curr == NULL)
        return NULL;
    else if(strcmp(name, curr->name) > 0)
        return searching(name, curr->right);
    else if(strcmp(name, curr->name) < 0)
        return searching(name, curr->left);
    else if(strcmp(name, curr->name) == 0){
        return curr;
    }
}

Node *update(int age, const char* name, Node *curr = root){
    if(curr == NULL)
        return NULL;
    else if(strcmp(name, curr->name) > 0)
        curr->right = update(age, name, curr->right);
    else if(strcmp(name, curr->name) < 0)
        curr->left = update(age, name, curr->left);
    else if(strcmp(name, curr->name) == 0)
        curr->age = age;
        return curr;
}

int main(){
    root = insertion(createNode("Budi", "1234567891", 20));
    root = insertion(createNode("Joko", "8723546421", 19));
    root = insertion(createNode("Indro", "1236783249", 20));
    root = insertion(createNode("Caca", "7634839898", 18));

    printf("=============\n");
    printf("  PreOrder\n\n");
    printf("=============\n");
    preOrder();

    printf("=============\n");
    printf("  InOrder\n");
    printf("=============\n");
    inOrder();

    printf("=============\n");
    printf("  PostOrder\n");
    printf("=============\n");
    postOrder();

    Node *result = searching("Caca");
    if(result) {
        printf("%s found!\n", result->name);
        printf("NIM : %s\n", result->nim);
    } else {
        printf("Data Not Found!!!\n");
    }

    printf("=============\n");
    printf("  PreOrder\n\n");
    printf("=============\n");
    preOrder();

    printf("=============\n");
    printf("  InOrder\n");
    printf("=============\n");
    inOrder();

    printf("=============\n");
    printf("  PostOrder\n");
    printf("=============\n");
    postOrder();

    root = update(25, "Budi");

    printf("=============\n");
    printf("  PreOrder\n\n");
    printf("=============\n");
    preOrder();

    printf("=============\n");
    printf("  InOrder\n");
    printf("=============\n");
    inOrder();

    printf("=============\n");
    printf("  PostOrder\n");
    printf("=============\n");
    postOrder();

    result->age = 30;

    printf("=============\n");
    printf("  PreOrder\n\n");
    printf("=============\n");
    preOrder();

    printf("=============\n");
    printf("  InOrder\n");
    printf("=============\n");
    inOrder();

    printf("=============\n");
    printf("  PostOrder\n");
    printf("=============\n");
    postOrder();

    return 0;
}