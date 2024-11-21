#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct data{
    int value;
    struct data *left, *right;
} data;

data *root = NULL;

data *createNode(int value){
    data *newNode = (data*)malloc(sizeof(data));
    newNode->value = value;

    newNode->left = newNode->right = NULL;
    return newNode;
}

data *push(data *newNode, data *curr = root){
    if(!curr) {
        return newNode;
    } else if (newNode->value > curr->value){
        curr->right = push(newNode, curr->right);
    } else if (newNode->value < curr->value){
        curr->left = push(newNode, curr->left);
    }
    return curr;
}

data *toDel(data *root, int key){
    if(!root){
        return root;
    }

    if(root->value > key){
        root->left = toDel(root->left, key);
        return root;
    } else if(root->value < key){
        root->right = toDel(root->right, key);
        return root;
    }

    if(!root->value){
        data *temp = root->right;
        free(root);
        return temp;
    } else if(!root->right) {
        data *temp =  root->left;
        free(root);
        return temp;
    } else {
        data *succParent = root;

        data *succ =  root->right;
        while (succ->left != NULL){
            succParent = succ;
            succ = succ->left;
        }

        if(succParent != root){
            succParent->left = succ->right;
        } else {
            succParent->right = succ->right;
        }

        root->value = succ->value;

        free(succ);
        return root;
    }
}

void inOrder(data *curr = root){
    if(curr){
        inOrder(curr->left);
        printf("%d ", curr->value); 
        inOrder(curr->right);
    } 
}

void postOrder(data *curr = root){
    if(curr){
        postOrder(curr->left);
        postOrder(curr->right);
        printf("%d ", curr->value); 
    } 
}

void preOrder(data *curr = root){
    if(curr){
        printf("%d ", curr->value); 
        preOrder(curr->left);
        preOrder(curr->right);
    } 
}

void addData(){
    int value;
    int totals;
    puts("");

    printf("Total Add data : ");
    scanf("%d", &totals); getchar();
    for(int i = 0; i < totals;i++){
        printf("Input Data ke - %d : ", i);
        scanf("%d", &value); getchar();
        root = push(createNode(value), root);
    }
}

void DelData(){
    int *target = (int*)malloc(5);
    do {
        printf("Input Data to Delete : ");
        scanf("%d", &*target); getchar();
    } while(!target);
    toDel(root, *target);
    puts("Successfully deleted data...\n");
}

int main(){
    int menu;

    do {
        printf("===================\n");
        printf("WELCOME BST PROGRAM\n");
        printf("===================\n");
        printf("1. Insert Data\n");
        printf("2. Delete Data\n");
        printf("3. View Data\n");
        printf("4. Exit\n");
        printf(">> ");
        scanf("%d", &menu);
        getchar();

        switch (menu){
            case 1:
                addData();
                break;
            case 2:
                DelData();
                break;
            case 3:
                int opt;
                do {
                    printf("Choose Notation : \n");
                    printf("I.   Preorder\n");
                    printf("II.  Postorder\n");
                    printf("III. Inorder\n");
                    printf("IV.  Exit\n");
                    printf(">> ");
                    scanf("%d", &opt); getchar();

                    switch(opt) {
                        case 1:
                            preOrder();
                            puts("");
                            break;
                        case 2:
                            postOrder();
                            puts("");
                            break;
                        case 3:
                            inOrder();
                            puts("");
                            break;
                    }
                } while (opt != 4);
                break;
        }
    }  while(menu != 4);
}