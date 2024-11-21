#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list{
    char name[30];
    int umur;
    int height;
    struct list *left, *right;
} node;

node *root = NULL;

node *createNode(int id, char *name, int umur){
    node *list = (node*)malloc(sizeof(node));
    strcpy(list->name, name);
    list->umur = umur;
    list->height = 1;
    list->left = list->right = NULL;

    return list;
}

int findMax(int a, int b){
    return (a > b) ? a : b;
}

int getHeight(node *root){
    return (root) ? root->height : 0;
}

int getBf(node *root){
    return (root) ? getHeight(root->left) - getHeight(root->right) : 0;
}

void updateHeight(node *root){
    root->height = findMax(getHeight(root->left), getHeight(root->right)) + 1;
}

node *leftRotate(node *root){
    node *right = root->right;
    node *rightleft =  right->left;

    root->right = rightleft;
    right->left = root;

    updateHeight(root);
    updateHeight(right);

    return right;
}

node *rightRotate(node *root){
    node *left = root->left;
    node *leftright =  left->right;

    root->left = leftright;
    left->right = root;

    updateHeight(root);
    updateHeight(left);

    return left;
}

node *balancing(node *root){
    if(!root) return NULL;

    updateHeight(root);

    int bf = getBf(root);

    if(bf > 1){
        if(getBf(root->left) < 0) root->left = leftRotate(root->left);
        root = rightRotate(root);
    } else if(bf < -1){
        if(getBf(root->right) > 0) root->right = rightRotate(root->right);
        root = leftRotate(root);
    }

    return root;
}

node *insertion(int id, char *name, int umur, node *root){
    if(!root) return createNode(id, name, umur);
    else if(umur < root->umur) root->left = insertion(umur, name, root->left);
    else if(umur > root->umur) root->right = insertion(umur, name, root->right);
    return balancing(root);
}

node *searching(int umur, node *root){
    if(!root) return NULL;
    else if(umur < root->umur) return searching(umur, root->left);
    else if(umur > root->umur) return searching(umur, root->right);
    return root;
}

node *del(int umur,node *root){
    if(!root) return NULL;
    if(umur < root->umur) root->left = del(umur, root->left);
    else if(umur > root->umur) root->right = del(umur, root->right);
    else {
        if(!root->left && !root->right){
            free(root);
            return NULL;
        } else if(!root->left){
            node *temp = root->right;
            free(root);
            return temp;
        } else if(!root->right){
            node *temp = root->left;
            free(root);
            return temp;
        } else {
            node *temp = root->left;
            while(root->right) temp = temp->right;
            strcpy(root->name, temp->name);
            root->umur = temp->umur;
            root->left = del(umur, root);
        }
    }
    return balancing(root);
}

void printList(node *root){
    if(root){
        printList(root->left);
        printf("Umur: %d, Name: %s\n", root->umur, root->name);
        printList(root->right);
    }
}

void deleteMenu(){
    int umur;
    printList(root);
    printf("Input umur to deleted: ");
    scanf("%d", &umur);
    getchar();

    root = del(umur, root);
}

void editMenu(){
    int umur;
    printList(root);
    printf("Input umur to update: ");
    scanf("%d", &umur);
    getchar();
    node *key = searching(umur, root);

    if(!key){
        printf("Umur Not Found\n");
        return;
    }

    char name[30];
    do{
        printf("Input Name : ");
        scanf("%[^\n]", name);
        getchar();
        int len = strlen(name);
    } while(len <= 2);

    strcpy(key->name, name);

}

void addList(){
    int umur;
    
    do {
        printf("Input Umur : ");
        scanf("%d", &umur);
        getchar();
    } while(umur <= 0);

    char name[30];
    do{
        printf("Input Name : ");
        scanf("%[^\n]", name);
        getchar();
        int len = strlen(name);
    } while(len <= len && len >= 40);

    root = insertion(umur, name, root);
}

void mainMenu(){
    while(true){
        int a;
        printf("Menu\n");
        printf("1. Add List\n");
        printf("2. Update List\n");
        printf("3. Delete Menu\n");
        printf("4. View List\n");
        printf("5. Exit\n");
        printf("Input Choice");
        scanf("%d", &a);
        getchar();

        if(a == 1){
            addList();
        } else if(a == 2){
            editMenu();
        } else if(a == 3){
            deleteMenu();
        } else if(a == 4){
            printList(root);
        } else if(a == 5){
            break;
        } else 
    }
}
